'''IMPORTS'''
import sys,os,json,random, pickle, ctypes

'''GLOBAL VARIABLES'''

DEBUG = False

global variables,toknum,fyunctions, arrays, pointers

declaredfunctions = {}
arrays = pointers  = {}
parts = {}

characters = ['+','=','#',","," ","/","*","-", "%"]
numchars = [0,1,2,3,4,5,6,7,8,9,"."]
comparators = ["==","!=","<=",">=","<",">","and","or","not"]
functions = ['write','if','var','roar',"input","int","string", "savedVar", "while","random","function", "savedVarDelete", "for", "system", "ptr","array","call","return", "memset"]
keywords = ["//", "auto"]
variables = {}
saved_variables = {}
b_values = ["true", "false", "REEEEEEEEEEEEEE"]

for i in range(1000):
      
  variables[i] = {}

'''CLASSES FOR SAVED VARIABLES'''

class JSON_saver:

  def __init__(self):
    pass

  def read(self,file_):


    self.file_ = file_

    return pickle.load(open(self.file_, "rb"))
  
  def writeDict(self,dictionary):


    saved_json = pickle.dumps(dictionary)
    f = open(self.file_, "wb")
    f.write(saved_json)
    f.close()



TO_RT = 'RT' 
TO_STRING = 'STRING'
TO_INT = 'INT'
TO_FLOAT = 'FLOAT'
TO_RBRACKET = 'RBRACKET'
TO_COMPARATOR = 'COMPARATOR'
TO_LBRACKET = 'LBRACKET'
TO_FUNCTION = 'BUILTIN_FUNCTION'
TO_KEYWORD = 'KEYWORD'
TO_SPECALCHARACTERS = 'SPECIALCHARACTERS'
TO_EOL = 'EOL'
TO_COMMENT = 'COMMENT'
TO_INTERNAL = 'INTERNALFUNCTION'
TO_MULTIPLY = 'MULTIPLY'
TO_DIVIDE = 'DIVIDE'
TO_PLUS = 'PLUS'
TO_MINUS = 'MINUS'
TO_OPERATIONS = 'OPERATORS'
TO_EQUALS = 'EQUALS'
TO_RCBRACKET = "RCBRACKET" 
TO_LCBRACKET = "LCBRACKET"
TO_FUNCTION_DEF = "FUNCTION"


def convertToInt(value):
  isInt = False
  try:
    value1 = int(value)
  except:
    return isInt,""
  isInt = True
  return isInt,int(value)

'''ERROR CLASS'''
class Error:
  def __init__( self, type_,line,file_, details):
    print(type_ + f'Error: In file {file_} (Line {line}), '+ details)
    __import__("time").sleep(10)
    __import__("sys").exit(-1)

class op_tok:
  def __init__(self, val, pos):
    self.val = val
  
  def __repr__(self):
    return f"Operator: {self.val}"

class int_tok:
  def __init__(self, val, pos):
    self.val = int(val)
  
  
  def __repr__(self):
    return f"Integer: {self.val}"

class float_tok:

  def __init__(self, val, pos):
    self.val= float(val)

  def __repr__(self):
    return f"Float: {self.val}"
  

'''MATHS CLASS'''
class Maths1:
    def __init__(self):
        self.argslist = []
    def parse(self,args):
        argslist = args
        try:
          for i in range(len(argslist)):
            if argslist[i] == None:
                
                del argslist[i]
            if argslist[-1].type == "INTERNALFUNCTION":
              
                del argslist[i]
        except:
          pass

        length = len(argslist)
        i = 0
        
        while length > 1:
          
          
          if argslist[i].type=="INTERNALFUNCTION":
            del argslist[i]
            length -= 1
            i -= 1
          
          if argslist[i].type == "SPECIALCHARACTERS":
            if argslist[i].value == "=":
              del argslist[i]
              length -= 1
              i -= 1
              
            elif argslist[i].value == "-":
              result = argslist[i-1].value - argslist[i+1].value
              argslist[i] = Token(argslist[i-1].type,result)
              del argslist[i+1]
              del argslist[i-1]
              length -= 2
              i -= 1
            
            elif argslist[i].value == "+":
              result = argslist[i-1].value + argslist[i+1].value
              argslist[i] = Token(argslist[i-1].type,result)
              del argslist[i+1]
              del argslist[i-1]
              length -= 2
              i -= 1

            elif argslist[i].value == "*":
              result = argslist[i-1].value * argslist[i+1].value
              argslist[i] = Token(argslist[i-1].type,result)
              del argslist[i+1]
              del argslist[i-1]
              length -= 2
              i -= 1
              
            elif argslist[i].value == "/":
              result = argslist[i-1].value / argslist[i+1].value
              argslist[i] = Token(argslist[i-1].type,result)
              del argslist[i+1]
              del argslist[i-1]
              length -= 2
              i -= 1

            elif argslist[i].value == "%":
              result = argslist[i-1].value % argslist[i+1].value
              argslist[i] = Token(argslist[i-1].type,result)
              del argslist[i+1]
              del argslist[i-1]
              length -= 2
              i -= 1


          i += 1
          continue
        return argslist
                    
        
    
class Struct:
  def __init__(self,keys,values,):
    self.keys = keys
    self.values = values
    self.struct = self.makeStruct()
  
  def makeStruct(self):
    res = {}

    if not len(self.keys) == len(self.values): return-1
    for i in range(len(self.keys)):
      res[self.keys[i]] = self.values[i]
    return res




'''TOKEN CLASS THAT LEXER RETURNS'''
class Token:
  def __init__(self, type, value=None,level=None, line = "unknown"):
    self.type = type
    self.value = value
    self.level = level
    self.line = line
    self.li = line
  def __repr__(self):
    return f"{self.type}:{self.value} on line {self.li}"


'''PARSER CLASSES'''
class BUILTIN_FUNCTION:
  def __init__(self,command,args):
    self.command = command
    self.args = args


class COMMENT:
  def __init__(self,command,args):
    self.command = 'comment'
    self.args = None




'''FILE INPUT CLASS'''
class fileInput:
  def __init__(self, fileName = None):
    self.fileName = fileName

  def getFile(self):
    try:
      fileName = sys.argv[1]
    except:
      fileName = input('No file was found to be run. Please input one now: ')

      if (not os.path.exists(fileName)):
        print("INVALID FILE NAME")
        sys.exit()

    
    self.fileName = fileName
    
  
  def getFileContents(self, fileName =  None):
    
    if fileName == None:
      fileName = self.fileName
    else:
      self.fileName = fileName

    if not os.path.exists(fileName):
      return -1
    else:
      file_ = open(fileName, 'rt')
      contents = file_.read()
      contents = str(contents).replace(r'\a\b\f\n\t','\a\b\f\n\t')
      
      if contents[-1] != "\n": contents += "\n"
      return contents
    
'''ANYASIS CLASS THAT RETURNS RAW TOKENS'''
global cbracketnum,bracketnum
cbracketnum = 0
bracketnum = 0
class Anyasis:

  def __init__(self): self.li = 0

  def make_command(self, text):
    global cbracketnum,bracketnum

    isString = False
    
    isNum = False
    command_parts = []
    current_text_list = ""
    currentnum = ""
    
    for i in range(len(text)):
      if text[i] == "{" and isString == False and isNum == False:
        cbracketnum += 1

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list ))
          current_text_list = ""
        
        command_parts.append(Token(TO_LCBRACKET, text[i],cbracketnum ))

        
        continue
      if text[i] == "}" and isString == False and isNum == False:

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list ))
          current_text_list = ""
        
        command_parts.append(Token(TO_RCBRACKET, text[i],cbracketnum ))
        cbracketnum -= 1
        continue
      if text[i] == "(" and isString == False and isNum == False:
        bracketnum += 1
        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list ))
          current_text_list = ""
        
        command_parts.append(Token(TO_LBRACKET, text[i],bracketnum ))
        
        continue
      if text[i] == ")" and isString == False and isNum == False:
        
        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list))
          current_text_list = ""

        command_parts.append(Token(TO_RBRACKET, text[i],bracketnum))
        bracketnum -= 1
        
        continue
      
      if text[i] == '"' and isString == True:
        isString = False
        command_parts.append(Token(TO_STRING, current_text_list,cbracketnum))
        current_text_list = ""
        continue
      elif text[i] == '"' and isString == False:
        isString = True

      else:
        
        if isString == False and text[i] == " " and current_text_list != "": 
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
          current_text_list = ""
        
        else:
          current_text_list += text[i]
    
    if current_text_list != "":
      command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
      current_text_list = ""

    return command_parts

'''LEXER CLASS'''
class Lexer:
  
  def __init__(self,file):
    self.token_return_list = []
    self.li = 1
    self.file = file
    self.current_tok = None
  
  def make_tokens(self,tok_list):
    self.token_return_list = tok_list
    for i in range(len(tok_list)):
      level = tok_list[i].level
      if tok_list[i].type == TO_RT:
        tok_list[i].value = tok_list[i].value.replace(" ","")
        tok_list[i].line = self.li
      self.current_tok = tok_list[i]
      if self.current_tok.type == TO_STRING:
        self.current_tok.value = self.current_tok.value.replace("{}","",)
        self.current_tok.line = self.li
      if self.current_tok.type != TO_STRING:
        self.current_tok.line = self.li
        gettype,newvalue = convertToInt(self.current_tok.value)
        if gettype == True:
          self.token_return_list[i] = Token(TO_INT, newvalue,level, line = self.li)
        
        if self.current_tok.value in functions:
          self.token_return_list[i] = Token(TO_FUNCTION, self.current_tok.value,level, line= self.li)
      
        if self.current_tok.value in comparators:
           self.token_return_list[i] = Token(TO_COMPARATOR, self.current_tok.value,level,  line = self.li)
           continue
        if self.current_tok.value in keywords:
          self.token_return_list[i] = Token(TO_KEYWORD, self.current_tok.value,level,  line = self.li)
          continue
        if self.current_tok.value in characters:
          if self.current_tok.value != "":
            self.token_return_list[i] = Token(TO_SPECALCHARACTERS, self.current_tok.value,level,  line = self.li)

        if self.current_tok.value not in functions:
 
          self.current_tok.line = self.li


    self.li +=1
    if DEBUG: print(self.li)
    return self.token_return_list
        
class Parser:
  def __init__(self):
    pass
    
  def selfparse(self,toks):
    return self.parse(toks)

  def parse(self,tok):
    commandlist = []
    
    toks = tok
    
    for i in range(len(toks)):
      
      if toks[i].type == "SPECIALCHARACTERS":
        if toks[i].value == "#":
          continue

      if toks[i].value == "//":
        toknum = i+1
        commandlist.append(BUILTIN_FUNCTION("comment", None))
        while toks[toknum] != TO_EOL:
          toks[toknum].type =TO_INTERNAL

          if toks[i].type == TO_EOL:
            break

          try:
            temp = (toks[toknum])
            i += 1
          except:
            print("testing")
            i -= 1
            return commandlist

      if toks[i].type == TO_INTERNAL:
        continue
      
      if toks[i].type == "BUILTIN_FUNCTION":
                
        if toks[i].value == "random":
          toknum = i + 1
          var1,var2 = toks[toknum].value,toks[toknum + 1].value
          commandlist.append(BUILTIN_FUNCTION("random",[var1,var2]))

        if toks[i].value == "for":
          conditionlist = []
          linetrue = False
          executelist = []
          toknum = i + 1
          if toks[toknum].type == TO_LBRACKET:
            level = toks[toknum].level
            
            toknum += 1 
            if toks[toknum].type != TO_LBRACKET:
              while linetrue == False:
                if toks[toknum].type != TO_RBRACKET: 
                                
                  conditionlist.append(toks[toknum])
                  toknum += 1
                if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
                  linetrue = True
                  toknum+= 1
                  
              linetrue = False
              getbracket = True
              while getbracket == True:
                
                if toks[toknum].type == TO_LCBRACKET: 
                  level = toks[toknum].level
                  
                  while linetrue == False:
                      
                      executelist.append(toks[toknum])
                        
                      if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                        
                        linetrue = True
                        
                        executelist1 = self.selfparse(executelist)
                        
                        commandlist.append((BUILTIN_FUNCTION("for",[conditionlist,executelist1])))
                        getbracket = False
                        
                        toknum = 0
                        break
                      toks[toknum] = Token(TO_INTERNAL)
                      toknum += 1
                toknum += 1
          toknum += 1  


        
        if toks[i].value == "if":
          conditionlist = []
          linetrue = False
          executelist = []
          toknum = i + 1
          if toks[toknum].type == TO_LBRACKET:
            level = toks[toknum].level
            
            toknum += 1 
            if toks[toknum].type != TO_LBRACKET:
              while linetrue == False:
                if toks[toknum].type != TO_RBRACKET: 
                                
                  conditionlist.append(toks[toknum])
                  toknum += 1
                if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
                  linetrue = True
                  toknum+= 1
                  
              linetrue = False
              getbracket = True
              while getbracket == True:
                
                if toks[toknum].type == TO_LCBRACKET: 
                  level = toks[toknum].level
                  
                  while linetrue == False:
                      
                       
                        
                      executelist.append(toks[toknum])
                      
                        
                      if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                        
                        
                        
                        linetrue = True
                        
                        executelist1 = self.selfparse(executelist)
                        
                        
                        commandlist.append((BUILTIN_FUNCTION("if",[conditionlist,executelist1])))
                        getbracket = False
                        
                        toknum = 0
                        break
                      toks[toknum] = Token(TO_INTERNAL)
                      toknum += 1
                toknum += 1
          toknum += 1      
             
        if toks[i].value == "system":
          name = ""
          md = None
          toknum = i+1
          while toks[toknum].type != TO_LBRACKET:
            toknum +=1
          toknum +=1
          while toks[toknum].type != TO_RBRACKET:
            if toks[toknum].type == TO_INT:
              md = toks[toknum].value

              toknum +=1
            if toks[toknum].type ==TO_SPECALCHARACTERS and toks[toknum].value == ",":
              toknum +=1
            name += toks[toknum].value
            name += " "
            toknum +=1
            if toks[toknum].type == TO_RBRACKET:
              i -= 2
              break

        

          commandlist.append(BUILTIN_FUNCTION("system",[md, name]))
      
        if toks[i].value == "memset":
          name =None
          md = None
          toknum = i+1
          while toks[toknum].type != TO_LBRACKET:
            toknum +=1
          toknum +=1
          while toks[toknum].type != TO_RBRACKET:
            
            md = toks[toknum]

            toknum +=1
            if toks[toknum].type ==TO_SPECALCHARACTERS and toks[toknum].value == ",":
              toknum +=1
            name =  toks[toknum]
            toknum +=1
            if toks[toknum].type == TO_RBRACKET:
              i -= 2
              break

          commandlist.append(BUILTIN_FUNCTION("memset",[md, name]))
            
        if toks[i].value == "function":
          argslist = []
          linetrue = False
          executelist = []
          toknum = i + 1
          name = toks[toknum]
          
          linetrue = False
          getbracket = True
          while getbracket == True:
            
            if toks[toknum].type == TO_LCBRACKET: 
              level = toks[toknum].level
              
              while linetrue == False:
                  
                    
                    
                  executelist.append(toks[toknum])
                  
                    
                  if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                    
                    
                    
                    linetrue = True
                    
                    executelist1 = self.selfparse(executelist)
                    
                    
                    commandlist.append((BUILTIN_FUNCTION("function",[name,executelist1])))
                    getbracket = False
                    
                    toknum = 0
                    break
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
            toknum += 1
          
        if toks[i].value == "var":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          toknum += 1
          level = toks[toknum].level
          

          while linetrue == False:
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            if toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("var",[varname,commandcontents,level]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1


        if toks[i].value == "ptr":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          commandcontents.append(toks[toknum])
          toknum += 1
                

          while linetrue == False:
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                pass
               
            if toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("ptr",commandcontents))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

        
        if toks[i].value == "savedVar":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          toknum += 1
                 
          

          while linetrue == False:
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            if toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("savedVar",[varname,commandcontents]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1
        if toks[i].value == "call":
          name = toks[i + 1].value
          commandlist.append(BUILTIN_FUNCTION("call",name))
          
        if toks[i].value == "savedVarDelete":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          toknum += 1
                 
          

          while linetrue == False:
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            if toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("savedVarDelete",[varname,commandcontents]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

        if toks[i].value == "while":
          conditionlist = []
          linetrue = False
          executelist = []
          toknum = i + 2
          if toks[toknum].type != TO_LBRACKET:
            level = toks[toknum].level
            while linetrue == False:
              if toks[toknum].type != TO_RBRACKET:            
                conditionlist.append(toks[toknum])
                toknum += 1
              if toks[toknum].type == TO_RBRACKET:
                linetrue = True
                toknum+= 1
            linetrue = False
            linetrue = False
            getbracket = True
            while getbracket == True:
              
              if toks[toknum].type == TO_LCBRACKET: 
                level = toks[toknum].level
                
                while linetrue == False:
                    
                      
                      
                    executelist.append(toks[toknum])
                    
                      
                    if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                      
                      
                      
                      linetrue = True
                      
                      
                      getbracket = False
                      
                      toknum = 0
                      break
                    toks[toknum] = Token(TO_INTERNAL)
                    toknum += 1
              toknum += 1



          try:
            l = conditionlist[0]
            c = conditionlist[1]
            r = conditionlist[2]
            print(conditionlist)
          except:
            print("ERROR: NEED 3 values")
          executelist = self.selfparse(executelist)

          commandlist.append(BUILTIN_FUNCTION("while",[
            [l,c,r],
            [executelist]
            ]))


        if toks[i].value == "write":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          
            
          

          while linetrue == False:
            
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            elif toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("write",[varname,commandcontents]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1
      if toks[i].value == "input":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          
            
          

          while linetrue == False:
            
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            elif toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("input",[varname,commandcontents]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

      if toks[i].value == "return":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          
                 
          

          while linetrue == False:
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            elif toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("return",[varname,commandcontents]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1
      
      if toks[i].value == "string":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          
            
          

          while linetrue == False:
            
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            elif toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("string",[varname,commandcontents]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1
      if toks[i].value == "int":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          
            
          

          while linetrue == False:
            
            
            if toks[toknum].type == TO_FUNCTION:
                
                functionline = []
                
                for o in range(len(toks)):
                    
                    if toks[toknum].type != TO_EOL: 
                             
                        functionline.append(toks[toknum])
                        
                        toks[toknum] = Token(TO_INTERNAL)
                        
                    elif toks[toknum].type == TO_EOL:
                        functionline.append(toks[toknum])
                        break
                    toknum += 1
                commandcontents.append(self.selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
               
           
            elif toks[toknum].type == TO_EOL:
              linetrue = True
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("int",[varname,commandcontents]))
              
              break
           
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1
      if toks[i].value == "struct":
      
        end = False
        commandcontents = ""    
        variablenames = []

        toknum += 1
        structName = toks[toknum]
        toknum += 1

        if toks[toknum] == TO_EQUALS:
          toknum += 1
    
        if toks[toknum] == TO_LBRACKET:
          toknum += 1

        while end == False:
          pass

      if toks[i].type == "SPECIALCHARACTERS":
        if toks[i].value == "#":
          continue
          
      
      
    return commandlist

'''INTERPRETER'''
class Interpreter:
  global variables
  def __init__(self):
    pass

  def selfrun(self,command_list):
      return self.run(command_list,1)
  def getvar(self,name,level):
      global variables
      returnvalue = None
      for i in range(1000):
        if len(variables[level+i + 1]) == 0:
              break
        else:
              variables[level+i + 1] = {}
      for i in range(level + 1):
            
            
            if name in list(variables[i].keys()):
                  
                  returnvalue = variables[i][name]
      
      return returnvalue
  def parsevalues(self,values):
    assignvalue = []
    
    for o in range(len(values)):
            
      value = values[o]
      
      if isinstance(value,int) == False:
        
        if isinstance(value,list):
          
          if isinstance(value[0],BUILTIN_FUNCTION):
              
              thing = self.selfrun([value[0]])
              assignvalue.append(thing)
              continue
        else:
          if value.type == TO_RT:
            assignvalue.append(self.getvar(value.value,value.level))
            if value.value in saved_variables:
              assignvalue.append(saved_variables[value.value])
            
            if value.value in pointers:
              assignvalue.append(saved_variables[value.value])
            
            continue

          if value.type == 'INTERNALFUNCTION':
            continue
          assignvalue.append(value)
          continue
      else:
          
          assignvalue.append(value)
          continue
        
    mathsclass = Maths1()

    
    output = mathsclass.parse(assignvalue)
    return output
  def run(self,command_list1,mode):
    
    md = mode
    command_list = command_list1
    
    store_list = command_list
    if DEBUG:
      for i in range(len(command_list)):
        print(command_list[i].command,end = " ")
        print(command_list[i].args,end = " ")
        print()
    
    for i in range(len(command_list)):
      current_command = command_list[i]
      
     
      if current_command.command == 'input':
        values = current_command.args[1]
        
        output = self.parsevalues(values)
        
        returner = input(output[0].value)
        returner = Token(output[0].type,returner,output[0].level)
        if md == 0:
          pass
        else:
          return returner
      if current_command.command == 'int':
        values = current_command.args[1]
        output = self.parsevalues(values)[0]
        output.type = TO_INT
        output.value = int(output.value)
        if md == 1:
          return output
      if current_command.command == 'string':
        values = current_command.args[1]
        output = self.parsevalues(values)[0]
        output.value = str(output.value)
        output.type = TO_STRING
        if md == 1:
          return output
      
      if current_command.command == 'write':
        values = current_command.args[1]
        output = self.parsevalues(values)
        
        #DONT TOUCH YOU IDIOTS THIS IS FOR WRITE COMMAND.
        print(output[0].value)

      if current_command.command == "for":
        md = None
        condition = current_command.args[0]
        code = current_command.args[1]
        start = condition[0]
        stop = condition[1]
        increment = condition[2]

        if start.type == TO_INT:
          pass

 
        if start.value.strip() == "auto":
          md = "auto"

        else:
          md = "std"

        if DEBUG:
          print(start)
          print(stop)
          print(increment)

        if md == "auto":
          # print("AUTO")

          #start, stop , value

          #auto   x     "hello world"
          #auto   x     y
          if stop.type == TO_RT and increment.type == TO_RT:
            if stop.value == increment.value:

              Error("Syntax", stop.line, fileControl.fileName, "both values of an auto loop may not be the same.")

          if stop.type != TO_RT:
            Error("Syntax",stop.line, fileControl.fileName, "assigner cannot be a string")
          else:
            assigner = stop.value
            # print(assigner)
          
          if isinstance(increment,str):
            looper = increment
            # print(looper)
          elif isinstance(increment, Token):
            if increment.type == TO_STRING:
              looper = increment.value
              # print(looper)
            if increment.type == TO_RT:
              looper =  variables[increment.value.strip()]
            
          for a in range(len(looper)):
            variables[assigner.strip()] = Token(TO_STRING,looper[a])
            self.selfrun(code)
            # print(variables)
            
        if md == "std":

          if start.type == TO_INT:
            c1 = start.value
          elif start.type == TO_RT:
            try:
              c1 = self.getvar(start.value.strip(), start.level)
              c1 = c1.value
            except: 
              c1 = None
              print("ERROR")
         
          if stop.type == TO_INT:
            c2 = stop.value
          elif stop.type == TO_RT:
            try:
              c2 = self.getvar(stop.value.strip(), stop.level)
              c2 = c2.value
            except: 
              c2 = None
              print("ERROR")
         
          if increment.type == TO_INT:
            c3 = increment.value
          elif increment.type == TO_RT:
            try:
              c3 = self.getvar(increment.value.strip(), increment.level)
              c3 = c3.value
            except: 
              c3 = None
              print("ERROR")


          for i in range(c1, c2, c3):
            self.selfrun(code)

            value = start.value

            variables[start.level][value].value = variables[start.level][value].value + c3


      
      if current_command.command == 'var':# interprit the raw token as variables and get the values. something to do tomoz. :) i want to die btw
        
        
        values = current_command.args[1]
        
        assignvalue = self.parsevalues(values)
        
        assignlevel = current_command.args[2]
        level = current_command.args[2]
        for o in range(level):
        
          if o == level:
            assignlevel = level
            break
          if len(variables[o]) != 0:
            if current_command.args[0] in list(variables[o]):
              
              assignlevel = o
              break
            
          else:
            assignlevel -= 1
          
        
        variables[assignlevel][current_command.args[0]] = assignvalue[0]        
      if (current_command.command == "savedVar"):

        global saved_variables

        var_name = current_command.args[0]
        var_val = current_command.args[1][1].value


        saved_variables[var_name] = Token(TO_RT, var_val)
      
      if (current_command.command == "savedVarDelete"):
        
        var_name = current_command.args[0]
        if var_name == "__all__":
          saved_variables = {}
        else:
          try:
            del saved_variables[var_name]
          except:
            pass


      if current_command.command == 'comment':
        print('', end = '')
      
      if current_command.command == 'roar':
        temp = current_command.args
        output = temp[0]
        varnames = temp[1]
        if "{}" in temp[0]:
          
          for i in range(len(temp[1])):
            
            output = output.replace("{}",str(variables.get(varnames[i])),1)
        output = output.upper()
        print(output)
      if current_command.command == "random":
        args = current_command.args
        int1,int2 = args[0],args[1]
        if md == 1:
          return Token(TO_INT,random.randint(int1,int2))
      if current_command.command == 'return':
        
        values = self.parsevalues(current_command.args[1])
        #values = current_command.args[1]
        if md == 1:
          return values[0]

      if current_command.command == "ptr":

        # print(current_command.args)
        if not current_command.args[0].type == TO_RT and current_command.args[2].type == TO_RT:
          print("error")
        
        if not current_command.args[3].value in variables:
          print(f"Error: pointer reference variable {current_command.args[3].value} is not intialised before assignment to pointer reference { current_command.args[1].value}")


        ptr = current_command.args[1]
        pointers[ptr.value] = id(variables[current_command.args[3].value])


        # a = 'This is a {sample} string'
        
        # buffSize = len(a)+1
        # size = sys.getsizeof(a)
        # offset = size - buffSize
        # start = a.find('{')
        # end = a.find('}') + 1
        # location = id(a)
        # ctypes.memset(location + offset + start, 0, end-start)
        # print(ctypes.string_at(id(a), sys.getsizeof(a)))



      if current_command.command == "RT":
        
        if current_command.args.value in declaredfunctions:
          self.selfrun(declaredfunctions[current_command.args.value])

      if current_command.command == 'call':
        temp = declaredfunctions
        temptest = temp.get(current_command.args)
        runner = temp.get(current_command.args)
       
        returner = self.selfrun(runner)
        
        declaredfunctions[current_command.args] = temptest
        if returner != None:
          return returner
      if current_command.command == "if":
        args = current_command.args
        conditions = args[0].copy()
        execute = args[1].copy()
        
        
        for i in range(len(conditions)):
          if conditions[i].type == TO_RT:
              
              conditions[i] = self.getvar(conditions[i].value,conditions[i].level)
              
        o = 0
        
        length = len(conditions)
        while length > 1 and o < length:
          
          if conditions[o].type == "COMPARATOR":
            
            if conditions[o].value == "==":
              
              if conditions[o-1].value == conditions[o+1].value:
                conditions[o] = True
                del conditions[o+1]
                del conditions[o-1]
                length -= 2
                o -= 1
                continue
              else:
                  conditions[o] = False
                  del conditions[o+1]
                  del conditions[o-1]
                  length -= 2
                  o -= 1
                  continue
            if conditions[o].value == "!=":
              
              if conditions[o-1].value != conditions[o+1].value:
                conditions[o] = True
                del conditions[o+1]
                del conditions[o-1]
                length -= 2
                o -= 1
                continue
              else:
                conditions[o] = False
                del conditions[o+1]
                del conditions[o-1]
                length -= 2
                o -= 1
                continue


          o += 1
        
        if conditions[0] == True:
          
          self.selfrun(execute)

        
      if current_command.command == "function":
        args = current_command.args
        name = args[0]
        execute = args[1]
        
        declaredfunctions[name.value] = execute


      if current_command.command == "memset":
        pointer_adress = current_command.args[0]
        value = current_command.args[1]

        a = value.value
        print("a: " + a)
        buffSize = len(a)+1
        size = sys.getsizeof(a)
        offset = size - buffSize
        start = a[1]
        end = a[-1]
        location = pointer_adress.value


        buffer = len(a) + 1
        
        #ctypes.memset(location, '16', len(a)+1)

        # write data into region at given offset 

        #ctypes.memset(a, bytes('$'.encode()),7);

        print(ctypes.string_at(id(a), sys.getsizeof(a)))

      
      if current_command.command == "system":
        OSmode = current_command.args[0]
        if OSmode == 0:
          #return an exit status
          returner = Token(TO_INT,os.system(current_command.args[1]))
        
        if OSmode == 1:
          #return the command output
          cmd = current_command.args[1]
          cmd = cmd.strip()
          cmd += " > out"
          os.system(cmd)
          f = open("out")
          returner_raw = f.read()
          returner = Token(TO_STRING, returner_raw)
        
        if md != 0:
          return returner
         
        
      if current_command.command == "struct":

        dictionary_struct_value = current_command.args
        Keys = dictionary_struct_value.keys()
        Values = []
        for Key in Keys:
          Values.append(dictionary_struct_value[Key])
        
        current_struct = Struct(Keys, Values)
    
      if current_command.command == "while":
        condition = current_command.args[0]
        code = current_command.args[1]
        code = code[0]

        try:
          float(condition[0])
        except:
          pass

        if condition[0].type != TO_STRING and condition[0].value in variables:
          pass
             

        def makeConditionResult(l,c,r):
          
          if l.type == TO_RT:
            l = self.getvar(l.value, l.level)
          else: 
            if (isinstance(l,Token)): l = l.value
          
          if r.type == TO_RT:
            r = self.getvar(r.value, r.level)
          else: 
            if (isinstance(r,Token)): r = r.value
          
          if (isinstance(l, Token)): l = l.value
          if (isinstance(r,Token)): r = r.value
          if (isinstance(c, Token)):c = c.value 


          if c == "==": 
            if l == r: return True
          
          if c== "!=":
            if l != r : return True

          
          if c == ">":
            if l > r: return True
          
          if c== "<":
            if l < r : return True
          
          else:
            return False

        while True:
          
          if makeConditionResult(condition[0], condition[1], condition[2]):
            
            self.selfrun(code)
          else:
            break
      command_list = store_list


'''END OF CLASSES AND COMMANDS'''




Settings = lambda f :  json.load(open(f))
settings = Settings("settings.json")

fileControl = fileInput()

saved_handler = JSON_saver()
saved_variables = saved_handler.read(settings["DATAFILE"])

lexer = Lexer(fileControl.fileName)
fileControl.getFile()
text = fileControl.getFileContents()
text = text.split('\n')
print() #newline before we start.
line = 0
tokens = []
for i in range(len(text)):
  line += 1
  fileAnyasis = Anyasis()
  current_tok = text[i]
  list_of_raw_tokens = fileAnyasis.make_command(current_tok)
  refined_tokens = lexer.make_tokens(list_of_raw_tokens)
  refined_tokens.append(Token(TO_EOL,line)) 

  if DEBUG:  
    """DEBUG INFORMATION"""

  for token1 in refined_tokens:
    tokens.append(token1)

parser = Parser()
interpreter = Interpreter()
commands = parser.parse(tokens)
interpreter.run(commands,0)

if DEBUG:
  print(variables)
  print(declaredfunctions)
  """DEBUG INFORMATION"""

  for i in range(len(commands)):
    print(commands[i].command,end = " ")
    print(commands[i].args,end = " ")
    print()

saved_handler.writeDict(saved_variables)
# print(arrays)
