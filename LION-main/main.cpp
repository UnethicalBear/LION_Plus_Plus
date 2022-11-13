// import sys
// import os
// import json
// import random 
// import pickle 
// import importlib
// from datetime import date as date

#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include <map>
#include <vector>


/*void LION_BDAY_MESSAGE():
  today = date.today()
  if today.day == 27 and today.month == 11:

    years_old = str(today.year - 2020)

    if years_old[-1] == "1":
      print(f"Happy {years_old}st Birthday, LION! ")
    
    elif years_old[-1] == "2":
      print(f"Happy {years_old}nd Birthday, LION! ")
    
    elif years_old[-1] == "3":
      print(f"Happy {years_old}rd Birthday, LION! ")

    else:
      print(f"Happy {years_old}th Birthday, LION! ")

LION_BDAY_MESSAGE()

*/

// GLOBAL VARIABLES
// tempfunctions = os.listdir("INTERNAL/Functions")
#define DEBUG false

// tempfunctions.remove("__pycache__")
// global variables,toknum,functions, arrays, pointers,fvariables, defaultClassMode,externalfunctions
// defaultClassMode = json.load(open("settings.json"))["defaultAccessSpecifier"]
// externalfunctions ={}
// runners = {}

// for i in range(len(tempfunctions)):
//   if ".py" in tempfunctions[i]:
//     temp = importlib.import_module('.'+tempfunctions[i].strip(".py"), 'INTERNAL.Functions')
//     commandimport = temp.command_list
//     for thing in commandimport:
//       externalfunctions[thing] = tempfunctions[i].strip(".py") 
      
//     runners[tempfunctions[i].strip(".py")] = temp


// if (DEBUG:
//   print(externalfunctions)

std::map<std::string,std::string> variables;
std::map<std::string,std::string> fVariables;
std::map<std::string,std::string> declaredFunctions;
std::map<std::string,std::string> importedFunctions;


// arrays = pointers     = {}
// parts                 = {}
// classes               = {}
// uninitialized_classes = {}
// variables             = {}
// saved_variables       = {}



std::vector<std::string> characters  = {"+","=","#"," ","/","*","-", "%",",", "->"};
std::vector<char> numchars           = {'0','1','2','3','4','5','6','7','8','9','.'};
std::vector<std::string> comparators = {"==","!=","<=",">=","<",">","and","or","not"};
std::vector<std::string> functions   = {"write","if","var","roar","input","int","string","delindex", "savedVar", "while","random","function", "savedVarDelete", "for", "system", "ptr","array","call","return", "memset", "extern", "import", "error","get","appendto","type","size","openfile", "class", "this", "new","del", "loc", "memread", "attach","dict"};
std::vector<std::string> keywords    = {"//", "auto", "private", "public","inherit", "/*", "*/"};
std::vector<std::string> bValues    = {"true", "false", "REEEEEEEEEEEEEE"};


// '''CLASSES FOR SAVED VARIABLES'''

class JSON_saver {

  JSON_saver(){
  
  }
  void 

  def read(self,file_):


    self.file_ = file_

    return pickle.load(open(self.file_, "rb"))
  
  def writeDict(self,dictionary):


    saved_json = pickle.dumps(dictionary)
    f = open(self.file_, "wb")
    f.write(saved_json)
    f.close()

// '''TOKEN TYPES'''

#define TO_RT  'RT' 
#define TO_DICT  'DICT'
#define TO_STRING  'STRING'
#define TO_INT  'INT'
#define TO_FLOAT  'FLOAT'
#define TO_RBRACKET  'RBRACKET'
#define TO_COMPARATOR  'COMPARATOR'
#define TO_LBRACKET  'LBRACKET'
#define TO_FUNCTION  'BUILTIN_FUNCTION'
#define TO_EXTERNALFUNCTION  'EXTERNAL_FUNCTION'
#define TO_KEYWORD  'KEYWORD'
#define TO_SPECIALCHARACTERS  'SPECIALCHARACTERS'
#define TO_EOL  'EOL'
#define TO_COMMENT  'COMMENT'
#define TO_INTERNAL  'INTERNALFUNCTION'
#define TO_MULTIPLY  'MULTIPLY'
#define TO_DIVIDE  'DIVIDE'
#define TO_PLUS  'PLUS'
#define TO_LIST  'LIST'
#define TO_MINUS  'MINUS'
#define TO_OPERATIONS  'OPERATORS'
#define TO_EQUALS  'EQUALS'
#define TO_RCBRACKET  "RCBRACKET" 
#define TO_LCBRACKET  "LCBRACKET"
#define TO_RSBRACKET  "RSBRACKET" 
#define TO_LSBRACKET  "LSBRACKET"
#define TO_FUNCTION_DEF  "FUNCTION"
#define TO_ERROR  'ERROR'
#define TO_NULL  'NULL'
#define TO_CALL_EXTERNAL  'EXTERNALCOMMAND'
#define TO_CLASS  'CLASS'
#define TO_BOOL  'BOOLEANVALUE'



class Classes:
  def __init__(self,inherit_list):
    self.inherit_list  inherit_list
    self.mode = defaultClassMode
    
class Functions:
  def __init__(self,executelist,argslist):
    self.argslist = argslist
    self.executelist = executelist

class Level_Handler:
  def __init__(self):
    self.isClass = False
    self.class_name = ""
    self.mode = defaultClassMode
    self.cl = {}

'''VARIABLE SCOPES'''

for i in range(2000):
  variables[i] = {"__internal":Level_Handler()}
    
def convertToInt(value):
  isInt = False
  try:
    value1 = int(value)
  except:
    return isInt,""
  isInt = True
  return isInt,value1

'''ERROR CLASS'''
class Error:
  def __init__( self, type_,line,file_, details):

    print(type_ + f'Error: [File `{file_}`: Line {line}]: '+ details)
    input("\nPress enter or return to close the application...")
    sys.exit(-1)  


'''MATHS CLASS'''
class Maths1:
    def __init__(self):
        self.argslist = []
    def selfparse(self,args):
      return self.parse(args)
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
        try:
          for r in range(len(argslist)):
            if argslist[r].type == TO_LBRACKET:
              
              level = argslist[r].level
              bracketnums = []
              first,last = r,0
              count = r + 1
              while True:
                if argslist[count].type != TO_RBRACKET:
                  
                  bracketnums.append(argslist[count])
                  count += 1
                else:
                  if argslist[count].level == level:
                    last = count
                    
                    value = self.selfparse(bracketnums)
                    
                    del argslist[first:last]
                    argslist[first] = value[0]
                    
                    break
        except:
          pass
        state = 0
        i = 0
        while True:
          try:
            
            if argslist[i].type=="INTERNALFUNCTION":
              del argslist[i]
              length -= 1
              i -= 1
            
            if argslist[i].type == "SPECIALCHARACTERS":
              if argslist[i].value == "=":
                del argslist[i]
                length -= 1
                i -= 1
              if state == 0:
                
                if argslist[i].value == "*":
                  result = argslist[i-1].value * argslist[i+1].value
                  argslist[i] = Token(argslist[i-1].type,result,argslist[i-1].level)
                  del argslist[i+1]
                  del argslist[i-1]
                  length -= 2
                  i -= 1
                  
                elif argslist[i].value == "/":
                  result = argslist[i-1].value / argslist[i+1].value
                  argslist[i] = Token(argslist[i-1].type,result,argslist[i-1].level)
                  del argslist[i+1]
                  del argslist[i-1]
                  length -= 2
                  i -= 1
              if state == 1:
                
                
                if argslist[i].value == "-":
                  result = argslist[i-1].value - argslist[i+1].value
                  argslist[i] = Token(argslist[i-1].type,result,argslist[i-1].level)
                  del argslist[i+1]
                  del argslist[i-1]
                  length -= 2
                  i -= 1
                
                elif argslist[i].value == "+":
                  result = argslist[i-1].value + argslist[i+1].value
                  argslist[i] = Token(argslist[i-1].type,result,argslist[i-1].level)
                  del argslist[i+1]
                  del argslist[i-1]
                  length -= 2
                  i -= 1
                
            i += 1
            continue
          except IndexError:
            if state == 0:
              state = 1
              i = 0
            elif state == 1:
              break
          except TypeError:
            Error("Type", argslist[i].line, fileControl.fileName, "invalid comparotor")
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
        print()
        print("INVALID FILE NAME")
        input("\nPress enter or return to close the application...")
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
    
      if contents != "": 
        if contents[-1] != "\n": contents += "\n"
      return contents
    
'''ANYASIS CLASS THAT RETURNS RAW TOKENS'''

global cbracketnum,bracketnum,sbracketnum
sbracketnum = 0
cbracketnum = 0
bracketnum = 0
class Anyasis:

  def __init__(self): self.li = 0

  def make_command(self, text):
    global cbracketnum,bracketnum,sbracketnum

    isString = False
    
    isNum = False
    command_parts = []
    current_text_list = ""
    
    for i in range(len(text)):
      
      if text[i] == "[" and isString == False and isNum == False:
        sbracketnum += 1

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_LSBRACKET, text[i],sbracketnum ))

        
        continue
      if text[i] == "]" and isString == False and isNum == False:

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_RSBRACKET, text[i],sbracketnum ))
        sbracketnum -= 1
        continue
      if text[i] == "{" and isString == False and isNum == False:
        cbracketnum += 1

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
          current_text_list = ""
        
        command_parts.append(Token(TO_LCBRACKET, text[i],cbracketnum ))

        
        continue
      if text[i] == "}" and isString == False and isNum == False:

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_RCBRACKET, text[i],cbracketnum ))
        cbracketnum -= 1
        continue
      if text[i] == "(" and isString == False and isNum == False:
        bracketnum += 1
        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_LBRACKET, text[i],bracketnum ))
        
        continue
      if text[i] == ")" and isString == False and isNum == False:
        
        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
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
        elif isString == False and text[i] == ",": 
          if current_text_list != "":
            command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
            current_text_list = ""
            command_parts.append(Token(TO_RT, ",",cbracketnum)
            )
            continue
          else:
            command_parts.append(Token(TO_RT, ",",cbracketnum))
          current_text_list = ""
          continue

        else:
          if text[i] == " ":
            if isString == True:
              current_text_list += text[i]
            else:
              continue
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
        self.current_tok.li = self.li
        self.current_tok.line = self.li
      if self.current_tok.type != TO_STRING:
        self.current_tok.line = self.li
        gettype,newvalue = convertToInt(self.current_tok.value)
        if gettype == True:
          self.token_return_list[i] = Token(TO_INT, newvalue,level, line = self.li)

        if self.current_tok.value in b_values:
          self.token_return_list[i] = Token(TO_BOOL, self.current_tok.value, level, line = self.li)
        
        if self.current_tok.value in functions:
          self.token_return_list[i] = Token(TO_FUNCTION, self.current_tok.value,level, line= self.li)
        if self.current_tok.value in externalfunctions:
          self.token_return_list[i] = Token("EXTERNAL_FUNCTION", self.current_tok.value,level, line= self.li)
      
        if self.current_tok.value in comparators:
          self.token_return_list[i] = Token(TO_COMPARATOR, self.current_tok.value,level,  line = self.li)
          continue
        if self.current_tok.value in keywords:
          self.token_return_list[i] = Token(TO_KEYWORD, self.current_tok.value,level,  line = self.li)
          continue
        if self.current_tok.value in characters:
          if self.current_tok.value != "":
            self.token_return_list[i] = Token(TO_SPECIALCHARACTERS, self.current_tok.value,level,  line = self.li)
        
        if self.current_tok.value not in functions:

          # self.current_tok.line = self.li
          self.token_return_list[i].line = self.li

    
    self.li +=1
    if DEBUG: print(self.li)
    return self.token_return_list
  
        
class Parser:
  def __init__(self):
    pass


  def parseargs(self, toks):
    args_toks = []
    temp_toks = []
    toks.append(Token(TO_SPECIALCHARACTERS, ","))
    for i in range(len(toks)):

      
      if toks[i].type != TO_SPECIALCHARACTERS :
        temp_toks.append(toks[i])

      
      else:
        if toks[i].value == ",":
          if len(temp_toks) == 1:
            args_toks.append(temp_toks)

          if len(temp_toks) >  1:
            args_toks.append(self.selfparse(temp_toks))

          if len(temp_toks) == 0:
            args_toks.append(None)

          
          temp_toks = []
        
        else:
          temp_toks.append(toks[i])
    
    
    return args_toks
          
      
    
  def selfparse(self,toks):
    return self.parse(toks)
  def parsevalues(self,toks,toknum1):
    linetrue = False
    commandcontents = []
    toknum = toknum1
    level = toks[toknum].level
          
    if toks[toknum].type == TO_LBRACKET:
      
      level = toks[toknum].level
      toknum += 1
    while linetrue == False:
            if toks[toknum].level == None:
              toks[toknum].level = 0
            if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
            
              return commandcontents
              linetrue = True
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
              
              return commandcontents
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

  def parse(self,tok):
    commandlist = []
    
    toks = tok
    
    for i in range(len(toks)):
      
      if toks[i].type == "SPECIALCHARACTERS":
        if toks[i].value == "#":
          continue

      if toks[i].value == "/*":
        isDone = False
        while True:
          try:
            
            if toks[i].type == TO_KEYWORD and toks[i].value == "*/" or isDone:

              i+=1
              commandlist.append(BUILTIN_FUNCTION("comment", None))
              break

            else:
              if not isDone:
                toks[i].type = TO_INTERNAL

            if i < len(toks) -1 :
              i += 1
              continue
            else:
              break
          
          except IndexError:
            Error("Syntax", "line", "file", "details")
        
        commandlist.append(BUILTIN_FUNCTION("comment", None))
          


      elif toks[i].value == "//":
        toknum = i+1
        commandlist.append(BUILTIN_FUNCTION("comment", None))
        while toks[toknum] != TO_EOL:
          toks[toknum].type =TO_INTERNAL

          if toks[i].type == TO_EOL:
            break

          try:
            temp = (toks[toknum])
            i += 1
            if DEBUG:
              print("COMMENTED: ", temp)
            del temp
          except:
            i -= 1
            return commandlist

      
      elif toks[i].type == TO_INTERNAL:
        continue


      elif toks[i].type == "EXTERNAL_FUNCTION":
        if toks[i].value in externalfunctions:
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          
          commandcontents = self.parsevalues(toks,toknum)
          
          
          commandlist.append(BUILTIN_FUNCTION(toks[i].value,commandcontents))

      elif toks[i].type == "BUILTIN_FUNCTION":

        if toks[i].value == "error":

          toknum = i +1
          linetrue = False

          tokens = []

          while not linetrue:

            if toks[toknum].type == TO_EOL:
              linetrue = True
            else:
              tokens.append(toks[toknum])
            toknum += 1
        
          commandlist.append(BUILTIN_FUNCTION("error", tokens))

      
        if toks[i].value == "this":

          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          tokens = self.parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("this", tokens))



        if toks[i].value == "class":

          inheritList = []
          linetrue = False
          executelist = []
          toknum = i + 1

          name = toks[toknum]

          toknum +=1
          
          if toks[toknum].type == TO_LBRACKET:
            level = toks[toknum].level
            
            toknum += 1 
            if toks[toknum].type != TO_LBRACKET:
              while linetrue == False:
                if toks[toknum].type != TO_RBRACKET: 
                                
                  inheritList.append(toks[toknum])
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

                        commandlist.append((BUILTIN_FUNCTION("class",[name, inheritList,executelist1])))
                        getbracket = False
                        
                        toknum = 0
                        break
                      toks[toknum] = Token(TO_INTERNAL)
                      toknum += 1
                toknum += 1
          toknum += 1  


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
        
        if toks[i].value == "get":
          linetrue = False
          
          commandcontents = []
          toknum = i + 2
          varname = toks[toknum].value
          level = toks[toknum].level
          toknum += 1
          
          commandcontents = self.parsevalues(toks,toknum)
          #print(varname,commandcontents,level)
          commandlist.append(BUILTIN_FUNCTION("get",[varname,commandcontents,level]))
        if toks[i].value == "delindex":
          linetrue = False
          
          commandcontents = []
          toknum = i + 2
          varname = toks[toknum].value
          level = toks[toknum].level
          toknum += 1
          
          commandcontents = self.parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("delindex",[varname,commandcontents,level]))
        if toks[i].value == "dict":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          level = toks[toknum].level
          
          if toks[toknum].type == TO_LSBRACKET:
            
            level = toks[toknum].level
            toknum += 1
          while linetrue == False:
                  if toks[toknum].level == None:
                    toks[toknum].level = 0
                  if toks[toknum].type == TO_RSBRACKET and toks[toknum].level == level:
                    
                    commandlist.append((BUILTIN_FUNCTION("dict",[commandcontents])))
                    linetrue = True
                    break
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
                    
                    
                    return commandcontents
                
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
        if toks[i].value == "array":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          level = toks[toknum].level
          
          if toks[toknum].type == TO_LSBRACKET:
            
            level = toks[toknum].level
            toknum += 1
          while linetrue == False:
                  if toks[toknum].level == None:
                    toks[toknum].level = 0
                  if toks[toknum].type == TO_RSBRACKET and toks[toknum].level == level:
                    
                    commandlist.append((BUILTIN_FUNCTION("array",[commandcontents])))
                    linetrue = True
                    break
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
                    
                    
                    return commandcontents
                
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
        if toks[i].value == "system":
          toknum = i+2
          md = toks[toknum-1].value

          name = self.selfparse(toks)
          print(name)
          commandlist.append(BUILTIN_FUNCTION("system",[md, name]))
      
        if toks[i].value == "memset":
          # name =None
          # md = None
          # toknum = i+1
          # while toks[toknum].type != TO_LBRACKET:
          #   toknum +=1
          # toknum +=1
          # while toks[toknum].type != TO_RBRACKET:
            
          #   md = toks[toknum]

          #   toknum +=1
          #   if toks[toknum].type ==TO_SPECIALCHARACTERS and toks[toknum].value == ",":
          #     toknum +=1
          #   name =  toks[toknum]
          #   toknum +=1
          #   if toks[toknum].type == TO_RBRACKET:
          #     i -= 2
          #     break
            linetrue = False
            commandcontents = []
            toknum = i + 1
            varname = toks[toknum].value
            commandcontents = self.parsevalues(toks,toknum)

            commandlist.append(
              BUILTIN_FUNCTION("memset", commandcontents)
            )
          
        if toks[i].value == "memread":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)

          commandlist.append(
            BUILTIN_FUNCTION("memread", commandcontents)
          )
        
        if toks[i].value == "loc":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)

          commandlist.append(
            BUILTIN_FUNCTION("loc", commandcontents)
          )
        

            
        if toks[i].value == "function":
          argslist = []
          linetrue = False
          executelist = []
          toknum = i + 1
          name = toks[toknum]
          argslist = []
          linetrue = False
          getbracket = True
          while getbracket == True:
            
            if toks[toknum].type == TO_LBRACKET: 
              level = toks[toknum].level
              toknum += 1
              while linetrue == False:
                  
                    
                  if toks[toknum].type == TO_RT:
                    argslist.append(toks[toknum])
                  
                    
                  if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
                    
                    
                    
                    linetrue = True
                    
                    
                    
                    
                    
                    getbracket = False
                    
                    
                    break
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
            toknum += 1
          getbracket = True
          
          linetrue = False
          
          while getbracket == True:
            
            if toks[toknum].type == TO_LCBRACKET: 
              level = toks[toknum].level
              
              while linetrue == False:
                  
                    
                    
                  executelist.append(toks[toknum])
                  
                    
                  if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                    
                    
                    
                    linetrue = True
                    
                    executelist1 = self.selfparse(executelist)
                    
                    
                    commandlist.append((BUILTIN_FUNCTION("function",[name,executelist1,argslist])))
                    getbracket = False
                    
                    toknum = 0
                    break
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
            toknum += 1
        if toks[i].value == "del":
          linetrue = False
          
          commandcontents = []
          toknum = i + 1
          varname= toks[toknum].level
          level = toks[toknum].level
          
          
          commandcontents = self.parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("del",[varname,commandcontents,level]))   
        if toks[i].value == "var":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          level = toks[toknum].level
          toknum += 1
          
          commandcontents = self.parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("var",[varname,commandcontents,level]))
              
            


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
        
        if toks[i].value == "import":
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
              
              commandlist.append(BUILTIN_FUNCTION("import",[varname,commandcontents]))
              
              break
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

        if toks[i].value == "extern":
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
              
              commandlist.append(BUILTIN_FUNCTION("extern",[varname,commandcontents]))

              break
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

          

        if toks[i].value == "call":
          name = toks[i + 1].value
          argslist = self.parsevalues(toks,i+2)
          
          commandlist.append(BUILTIN_FUNCTION("call",[name,argslist]))
          
        if toks[i].value == "savedVarDelete":
          
          print("hello world!hi")

          lineToks = []
          toknum = i + 1
          
          print(toknum)

          while toks[toknum].type != TO_EOL:
            lineToks.append(toks[toknum])
            toknum += 1

          print(lineToks)
          commandlist.append(BUILTIN_FUNCTION("savedVarDelete",[]))
            
          

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
            
          except:
            print("ERROR: NEED 3 values")
          executelist = self.selfparse(executelist)

          commandlist.append(BUILTIN_FUNCTION("while",[
            [l,c,r],
            [executelist]
            ]))

        if toks[i].value == "openfile":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("openfile",[varname,commandcontents]))

        if toks[i].value == "attach":
          
          linetrue = False
          commandcontents = []
          toknum = i + 2
          varname = toks[toknum].value
          num = None


          for x in toks[toknum:]:
            if x.type == TO_RBRACKET:
              num = toks.index(x)
              break

          if num == None: 
            Error("Syntax", toks[toknum-2].li, fileControl.fileName, "Unmatched Bracket")
          commandcontents = (self.parseargs(toks[toknum:num]))

          
          
          commandlist.append(BUILTIN_FUNCTION("attach",[varname,commandcontents]))
        
        if toks[i].value == "write":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)
          
          
          commandlist.append(BUILTIN_FUNCTION("write",[varname,commandcontents]))

        if toks[i].value == "size":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("size",[varname,commandcontents]))
        if toks[i].value == "type":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("type",[varname,commandcontents]))
              
              
            
          
      if toks[i].value == "appendto":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("appendto",[varname,commandcontents]))
      if toks[i].value == "input":
          
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum) 
          commandlist.append(BUILTIN_FUNCTION("input",[varname,commandcontents]))
              
              
      
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

      if toks[i].value == "new":
        linetrue = False
        commandcontents = []
        toknum = i + 1
        varname = toks[toknum].value
        commandcontents = self.parsevalues(toks,toknum)
        commandlist.append(BUILTIN_FUNCTION("new",[varname,commandcontents]))
                                              
      if toks[i].value == "string":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)
          commandlist.append(BUILTIN_FUNCTION("string",[varname,commandcontents]))
              
              
      if toks[i].value == "int":
          linetrue = False
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = self.parsevalues(toks,toknum)
          commandlist.append(BUILTIN_FUNCTION("int",[varname,commandcontents]))
      # if toks[i].value == "struct":
      
      #   end = False
      #   commandcontents = ""    
      #   variablenames = []

      #   toknum += 1
      #   structName = toks[toknum]
      #   toknum += 1

      #   if toks[toknum] == TO_EQUALS:
      #     toknum += 1
    
      #   if toks[toknum] == TO_LBRACKET:
      #     toknum += 1

      #   while end == False:
      #     pass

      if toks[i].type == "SPECIALCHARACTERS":
        if toks[i].value == "#":
          continue
      
      if toks[i].type == TO_KEYWORD and toks[i].value in ["public","inherit","private"]:
        commandlist.append(BUILTIN_FUNCTION("ACCESS_SPECIFIER",toks[i]))          
      
    
    return commandlist

'''INTERPRETER'''
class Interpreter:
  global variables,externalfunctions
  def __init__(self):
    pass
  def functionrun(self,executelist,variableslist):
    global variables
    if len(variableslist) != 0:
      for key,item in variableslist.items():
        variables[1][key] = item
    
    return self.selfrun(executelist)
  def selfrun(self,command_list, classAppend = None):
      return self.run(command_list,1, classAppend)
  
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
  
  def checkBooleanCondition(self,argslist):
    print(argslist)

    for i in range(len(argslist)):
      if argslist[i].type == TO_COMPARATOR:

        LHS = argslist[i-1]
        RHS = argslist[i+1]
        COM_ = argslist[i]

        if LHS.type == TO_RT:
          LHS = self.getvar(LHS.value, LHS.level)
          print("LHS:", LHS)
          if LHS == None:
            Error("Name",LHS.line, fileControl.fileName, f"Variable {LHS.value} is not defined")

        if RHS.type == TO_RT:
          RHS = self.getvar(RHS.value, RHS.level)
          print("RHS:", RHS)
          if RHS == None:
            Error("Name",RHS.line, fileControl.fileName, f"Variable {RHS.value} is not defined")

        COM = COM_.value
        
        if COM == "==":
          if LHS.value == RHS.value:
            return True
          else:
            return False
        
        if COM == "===":
          if LHS.value == RHS.value and LHS.type == RHS.type:
            return True
          else:
            return False
        
        if COM == "!=":
          if LHS.value != RHS.value:
            return True
          else:
            return False
        
        if COM == "!==":
          if LHS.value != RHS.value and LHS.type != RHS.type:
            return True
          else:
            return False

        if COM == ">":
          if not ( LHS.type in [TO_INT, TO_FLOAT] and RHS.type in [TO_INT, TO_FLOAT]):
            Error("Comparator", COM_.line, fileControl.fileName, "Comparator > is not valid on types that are not INT or FLOAT")
          if LHS.value == RHS.value:
            return True
          else:
            return False

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
            
            variable = self.getvar(value.value,value.level)
            
            if variable == None:
              Error("Undefined", value.line, fileControl.fileName, "variable referenced before assignment")
            assignvalue.append(variable)
            

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


  
  def run(self,command_list1,mode, classAppend = None):
    md = mode
    command_list = command_list1
    global fvariables,variables
    store_list = command_list
    
    if DEBUG:
      for i in range(len(command_list)):
        print(command_list[i].command,end = " ")
        print(command_list[i].args,end = " ")
        print()
    for i in range(len(command_list)):
      current_command = command_list[i]
      
      if current_command.command in externalfunctions:
        
          variables,returner = runners[externalfunctions[current_command.command]].run(current_command,variables)
        
          if returner != None and md == 1:
            return returner
      
      if current_command.command == "ACCESS_SPECIFIER":
      
        variables[current_command.args.level - 1]["__internal"].mode = current_command.args.value


      if current_command.command == 'array':
        values = current_command.args[0].copy()
        assign = []
        tempargslist = [[]]
        argnum = 0
        if len(values) == 0:
          if md != 0:
          
            return Token(TO_LIST,[])
          continue
        for arg in values:
          if arg.value != ",":
            tempargslist[argnum].append(arg)
          else:
            if arg.value == ",":
              tempargslist.append([])
              argnum += 1
        for i in range(len(tempargslist)):
            assign.append(self.parsevalues(tempargslist[i]))
            assign[i] = assign[i][0]
        if md != 0:
          
          return Token(TO_LIST,assign,values[0].line)
        
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
        try:
          output.value = int(output.value)
        except:
          Error("Type", output.line, fileControl.fileName, "number of args for function does not match required number")
        if md == 1:
          return output
      if current_command.command == 'string':
        values = current_command.args[1]
        output = self.parsevalues(values)[0]
        output.value = str(output.value)
        output.type = TO_STRING
        if md == 1:
          return output

      if current_command.command == "error":

        if len(current_command.args) != 2:
          Error("Syntax", current_command.args[0].li,fileControl.fileName, "Invalid Syntax")

        Error(current_command.args[0].value, current_command.args[1].li, fileControl.fileName,current_command.args[1].value )
        
      if current_command.command == 'attach':


        values = current_command.args[1]
        functionTemplate = values[0][0]
        functionAssign   = values[1][0]
        deleteTemplate   = values[2][0]



        if classAppend != None:

          
          classAppend.cl[classAppend.class_name].inherit_list[classAppend.cl[classAppend.class_name].mode][functionAssign.value] = declaredfunctions[functionTemplate.value]
        
        else:
          declaredfunctions[functionAssign.value] = declaredfunctions[functionTemplate.value]

        if deleteTemplate.value == "1":
          del declaredfunctions[functionTemplate.value]



      if current_command.command == 'write':
        values = current_command.args[1]
        
        output = self.parsevalues(values)
        
        #DONT TOUCH YOU IDIOTS THIS IS FOR WRITE COMMAND.
        print(output[0].value)

      if current_command.command == 'openfile':
        values = current_command.args[1]
        print(values)
        output = self.parsevalues(values)

        
        
        print(output[0].value)
      if current_command.command == 'size':
        values = current_command.args[1]
        try:
          output = self.parsevalues(values)
        
          output = Token(TO_INT,len(output[0].value),output[0].line)
        except:
          Error("Attribute", output[0].line,fileControl.fileName, str(output[0]) + " has no size")
        if md == 1:
          return output
      
      if current_command.command == 'appendto':
        
        values = current_command.args[1].copy()
        
        name = values[0]
        output = []
        del values[0]
        assignlevel = values[0].level
        level = values[0].level
        for o in range(level):
        
          if o == level:
            assignlevel = level
            break
          if len(variables[o]) != 0:
            if name.value in list(variables[o]):
              
              assignlevel = o
              break
            
          else:
            assignlevel -= 1
        
        for arg in values:
          if arg.type != TO_SPECIALCHARACTERS:
            output.append(arg)
          else:
            if arg.value != ",":
              output.append(arg)
        output = self.parsevalues(output)
        if isinstance(variables[assignlevel][name.value].value,list) == False:
          Error("Type", assignlevel, fileControl.fileName,"variable is not list")
        try:
          variables[assignlevel][name.value].value.append(output[0])
        except:
          Error("Undefined", assignlevel, fileControl.fileName,"variable is not defined")

        
      if current_command.command == 'get':
        
        name = current_command.args[0]
        
        args = current_command.args[1].copy()
        
        try:
          for i in range(len(args)):
            if args[i].type == TO_LSBRACKET or args[i].type == TO_RSBRACKET:
              del args[i]
        except:
          pass
        args = self.parsevalues(args)[0]
        assignlevel = args.level
        level = args.level
        for o in range(level):
        
          if o == level:
            assignlevel = level
            break
          if len(variables[o]) != 0:
            
            if name in list(variables[o]):
              
              assignlevel = o
              break
            
          else:
            assignlevel -= 1
        if args.type == TO_RSBRACKET:
          Error("Syntax", assignlevel, fileControl.fileName, "no index given")
        
        try:

          if name in classes:
            try:
              tmp = classes[name].inherit_list["public"][args.value]
              if isinstance(tmp, Token):
                returner = tmp
              elif isinstance(tmp,Functions):
                #print("wir haben eine funktion")
                returner = self.functionrun(tmp.executelist,[])
            except:
              Error("Class", args.line, fileControl.fileName, "field does not exist, did you put the variable in public?")
          
          elif args.value in globals()["saved_variables"]:
            try:
              returner = globals()["saved_variables"][args.value]
            except:
              Error("Name", args.line, fileControl.fileName, "saved variable does not exist.")
          
          else:
            try:
              returner = variables[assignlevel][name].value[args.value]
            except:
              Error("Name", args.line, fileControl.fileName, "variable is not defined")

        except IndexError:
          Error("Index", args.line, fileControl.fileName, "list index out of range")
        except KeyError:
          Error("Key", args.line, fileControl.fileName, "unknown invalid key")
        
              

        if md == 1:
          return returner
      if current_command.command == 'dict':
        name = current_command.command
        args = current_command.args[0].copy()
        assign = {}
        tempname = []
        tempassign = []
        
        for i in range(len(args)):
          print(args[i])
          if args[i].type != "RT" and args[i].value != ":":
            tempname.append(args[i])
            
            
          else:
            
            for o in range(len(args)-i):
              
              print("2",args[o+i])
              if args[o+i].type != TO_SPECIALCHARACTERS and args[o+i].value != ",":
                tempassign.append(args[o+i])
                
              else:
                
                #tempname=self.parsevalues(tempname)
                
                #tempassign = self.parsevalues(tempassign)
                assign[tempname[0]] = Token(TO_DICT,tempassign,tempassign[0].level)
        print("RETURNER",assign)
        return assign
      if current_command.command == 'delindex':
        name = current_command.args[0]
        args = current_command.args[1].copy()
        
        try:
          for i in range(len(args)):
            if args[i].type == TO_LSBRACKET or args[i].type == TO_RSBRACKET:
              del args[i]
        except:
          pass
        args = self.parsevalues(args)[0]
        assignlevel = args.level
        level = args.level
        for o in range(level):
        
          if o == level:
            assignlevel = level
            break
          if len(variables[o]) != 0:
            if name.value in list(variables[o]):
              
              assignlevel = o
              break
            
          else:
            assignlevel -= 1
        if args.type == TO_RSBRACKET:
          Error("Syntax", assignlevel, fileControl.fileName, "no index given")
        
        try:
          dellist = variables[assignlevel][name].value
          
          del dellist[args.value]
          variables[assignlevel][name].value[args.value] = dellist
        except IndexError:
          Error("Index", args.line, fileControl.fileName, "list index out of range")
        except KeyError:
          Error("Key", args.line, fileControl.fileName, "invalid key")
        if md == 1:
          return returner
        

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
          print(start, " ", stop, " ", increment)

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
          if isinstance(increment,str):
            looper = increment
          elif isinstance(increment, Token):
            if increment.type == TO_STRING:
              looper = increment.value
            if increment.type == TO_RT:
              looper =  variables[increment.value.strip()]
            
          for a in range(len(looper)):
            variables[assigner.strip()] = Token(TO_STRING,looper[a])
            self.selfrun(code)
            
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
      
        
      if current_command.command == "include":
        module = current_command.args
        l = Lexer(module)
        iT = fileControl.getFileContents(module)
        iT = iT.split('\n')
        li = 0
        iTokens = []
        for i in range(len(text)):
          li += 1
          fA = Anyasis()
          ct = text[i]
          raw_tokens = fA.make_command(ct)
          rf_t = l.make_tokens(raw_tokens)
          rf_t.append(Token(TO_EOL,li)) 
          for token1 in rf_t:
            iTokens.append(token1)
          del token1
        pa = Parser()
        iN = Interpreter()
        cmds = pa.parse(iTokens)
        iN.run(cmds,0)
      if current_command.command == 'del':
        name = current_command.args[0]
        args = current_command.args[1].copy()
        
        try:
          for i in range(len(args)):
            if args[i].type == TO_LSBRACKET or args[i].type == TO_RSBRACKET:
              del args[i]
        except:
          pass
        args = args[0]
        assignlevel = args.level
        level = args.level
        for o in range(level):
        
          if o == level:
            assignlevel = level
            break
          if len(variables[o]) != 0:
            if name.value in list(variables[o]):
              
              assignlevel = o
              break
            
          else:
            assignlevel -= 1
        
        del variables[assignlevel][args.value]
      
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

        if classAppend != None:
          classAppend.cl[classAppend.class_name].inherit_list[classAppend.mode][current_command.args[0]] = assignvalue[0]
          
          
        else:
          variables[assignlevel][current_command.args[0]] = assignvalue[0]        
      if (current_command.command == "savedVar"):

        var_name = current_command.args[0]
        var_val = current_command.args[1][1].value


        globals()["saved_variables"][var_name] = Token(TO_RT, var_val)
      
      if (current_command.command == "savedVarDelete"):

        
        var_name = current_command.args[0]

        print(var_name)
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
      
      if current_command.command == "type":

        args = self.parsevalues(current_command.args[1])[0]
        args.value = args.type
        args.type = TO_STRING
        
        if md == 1:

          return args

      
      if current_command.command == 'call':
        temp = declaredfunctions.copy()
        
        runner = temp.get(current_command.args[0]).executelist.copy()
        argslist =  current_command.args[1].copy()
        
        calledfunctionargs = declaredfunctions[current_command.args[0]].argslist.copy()
        
        tempargslist = [[]]
        argnum = 0
        print(argslist)
        for arg in argslist:
          if isinstance(arg,list):
            tempargslist[argnum].append(self.selfrun(arg))
            continue
          if arg.value != ",":
            tempargslist[argnum].append(arg)
          else:
            if arg.value == ",":
              tempargslist.append([])
              argnum += 1
        argslist = tempargslist
        print(tempargslist)
        funcvariables = {}
        if len(calledfunctionargs) > 0:
          if len(calledfunctionargs) != len(argslist):
            Error("UserFunction", calledfunctionargs[0].line, fileControl.fileName, "number of args for function does not match required number")
          
          for i in range(len(argslist)):
            if argslist[i] == []:
              
                Error("UserFunction", calledfunctionargs[0].line, fileControl.fileName, f"required arg {calledfunctionargs[i].value} is empty")
            argslist[i] = self.parsevalues(argslist[i])
            funcvariables[calledfunctionargs[i].value] = argslist[i][0]
        
        returner = self.functionrun(runner,funcvariables)
        
        #argslist = self.parsevalues(argslist)
        
        if returner != None:
          return returner

      if current_command.command == "extern":

        cmd = current_command.args[0]
        args = current_command.args[1]

        if not cmd.strip() in imported_functions:
          Error("Import", "None", "None", "None" )

        external_cmd = imported_functions[cmd]
        external_cmd(args)

      if current_command.command == "this":


        if current_command.args[0].type == TO_SPECIALCHARACTERS and current_command.args[0].value == "->":

          runner_list = current_command.args[1:]


          self.selfrun(runner_list[0], classAppend = variables[current_command.args[0].level - 1]["__internal"])

        

      if current_command.command == "class":

        variables[current_command.args[0].level]["__internal"].class_name = current_command.args[0].value
        
        variables[current_command.args[0].level]["__internal"].isClass = True
        
        uninitialized_classes[current_command.args[0].value] = current_command.args[0].level

        variables[current_command.args[0].level]["__internal"].cl[current_command.args[0].value] = Classes({
          "public":{},
          "inherit":{},
          "private":{}
        })


        self.selfrun(current_command.args[2])


      if current_command.command == "new":

        del current_command.args[1][1]
        

        if current_command.args[1][0].value in uninitialized_classes:
        
          classes[current_command.args[1][1].value] = variables[uninitialized_classes[current_command.args[1][0].value]]["__internal"].cl[current_command.args[1][0].value]

          editedInheritList = classes[current_command.args[1][1].value].inherit_list
          editedInheritList["private"].update(editedInheritList["inherit"])
          editedInheritList["inherit"] = {}
        
          classes[current_command.args[1][1].value].inherit_list  = editedInheritList

        else:
          Error("Name", current_command.args[0].line, fileControl.fileName, "Class does not exist")
        


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
        argslist = args[2]

        if classAppend != None:
          classAppend.cl[classAppend.class_name].inherit_list[classAppend.mode][name.value] = Functions(execute, argslist)

        else:
          declaredfunctions[name.value] = Functions(execute,argslist)


      if current_command.command == "loc":

        var = self.getvar(current_command.args[0].value, current_command.args[0].level)

        if md == 0:
          pass
        if md == 1:
          return Token(TO_INT, hex(id(var)))

      
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

        while True:
          res = self.checkBooleanCondition(condition)
          print(res)
          if res:
            self.selfrun(code)
          else:
            break
            
      command_list = store_list


'''END OF CLASSES AND COMMANDS'''
Settings = lambda f :  json.load(open(f))
settings = Settings("settings.json")

try: 

  fileControl = fileInput()

  saved_handler = JSON_saver()
  saved_variables = saved_handler.read(settings["dataFile"])
  defaultClassMode = settings["defaultAccessSpecifier"]

  lexer = Lexer(fileControl.fileName)
  fileControl.getFile()
  text = fileControl.getFileContents()
  text = text.split('\n')

  def removeLast(text:str):
    r = ""
    for i in range(len(list(text))):
      if text[i] == " " and i == len(text) - 1:
        break
      else:
        r+=text[i]
    return r

  for i in range(len(text)):
    
    try: t = text[i][-1]
    except: continue
    if text[i][-1] == " ": 
      text[i] = removeLast(text[i])


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
  input("\nPress enter or return to close the application...")

except Exception as e:
  print(fsefhkjshkfjs)
  today = date.today()
  f = open("log.txt","a")

  exc_type, exc_obj, exc_tb = sys.exc_info()
  fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
  #'print(exc_type, fname, exc_tb.tb_lineno)
  
  print('Uncaught Error! Code: {c}, Message: {m}'.format(c = type(e).__name__, m = str(e)))
  
  if settings["autoDumpError"] == False:
    dump = input("Dump Error to log.txt? y/n: ")
  else:
    dump = "y"

  if dump.lower() == "y":
    f.write("Error: " + str(today) + " \n" + str(exc_type) + " " +  str(fname) + " line:" +  str(exc_tb.tb_lineno))
    f.write(' Code: {c}, Message: {m}'.format(c = type(e).__name__, m = str(e)) + "\n")


    #f.write(f'Error Type: {type(e).__name__,}, Message: {str(e)} When attempting to run file: {fileHandler.fileName}')

  else:
    pass
  f.close()
    
    
# we used some memory, so let's give it back

globals__ = globals()
keys = list(globals__.keys())
for y in range(len(globals__)):
  try:
    if keys[y] != "globals__":
      del (globals__[keys[y]])
    else:
      continue
  except IndexError:
    break
del globals__, keys, y 