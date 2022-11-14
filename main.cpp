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
      std::cout << f"Happy {years_old}st Birthday, LION! ")

    elif years_old[-1] == "2":
      std::cout << f"Happy {years_old}nd Birthday, LION! ")

    elif years_old[-1] == "3":
      std::cout << f"Happy {years_old}rd Birthday, LION! ")

    else:
      std::cout << f"Happy {years_old}th Birthday, LION! ")

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
//   std::cout << externalfunctions)

std::map<std::string, std::string> variables;
std::map<std::string, std::string> fVariables;
std::map<std::string, std::string> declaredFunctions;
std::map<std::string, std::string> importedFunctions;

// arrays = pointers     = {}
// parts                 = {}
// classes               = {}
// uninitialized_classes = {}
// variables             = {}
// saved_variables       = {}

std::vector<std::string> characters = {"+", "=", "#", " ", "/", "*", "-", "%", ",", "->"};
std::vector<char> numchars = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
std::vector<std::string> comparators = {"==", "!=", "<=", ">=", "<", ">", "and", "or", "not"};
std::vector<std::string> functions = {"write", "if", "var", "roar", "input", "int", "string", "delindex", "savedVar", "while", "random", "function", "savedVarDelete", "for", "system", "ptr", "array", "call", "return", "memset", "extern", "import", "error", "get", "appendto", "type", "size", "openfile", "class", "this", "new", "del", "loc", "memread", "attach", "dict"};
std::vector<std::string> keywords = {"//", "auto", "private", "public", "inherit", "/*", "*/"};
std::vector<std::string> bValues = {"true", "false", "REEEEEEEEEEEEEE"};

// CLASSES FOR SAVED VARIABLES

class JSON_saver
{ // this class needs to be able to read a binary and convert it to JSON and vice versa.

private:
  std::string file;

public:
  JSON_saver()
  {
  }
  void read(std::string file)
  {
    this->file = file;
    // return pickle.load(open(this->file_, "rb"))
  }

  void writeDict(std::map<std::string, std::string> dictionary)
  {

    // saved_json = pickle.dumps(dictionary)
    // f = open(this->file_, "wb")
    // f.write(saved_json)
    // f.close()
  }
};

// TOKEN TYPES

#define TO_RT "RT"
#define TO_DICT "DICT"
#define TO_STRING "STRING"
#define TO_INT "INT"
#define TO_FLOAT "FLOAT"
#define TO_RBRACKET "RBRACKET"
#define TO_COMPARATOR "COMPARATOR"
#define TO_LBRACKET "LBRACKET"
#define TO_FUNCTION "BUILTIN_FUNCTION"
#define TO_EXTERNALFUNCTION "EXTERNAL_FUNCTION"
#define TO_KEYWORD "KEYWORD"
#define TO_SPECIALCHARACTERS "SPECIALCHARACTERS"
#define TO_EOL "EOL"
#define TO_COMMENT "COMMENT"
#define TO_INTERNAL "INTERNALFUNCTION"
#define TO_MULTIPLY "MULTIPLY"
#define TO_DIVIDE "DIVIDE"
#define TO_PLUS "PLUS"
#define TO_LIST "LIST"
#define TO_MINUS "MINUS"
#define TO_OPERATIONS "OPERATORS"
#define TO_EQUALS "EQUALS"
#define TO_RCBRACKET "RCBRACKET"
#define TO_LCBRACKET "LCBRACKET"
#define TO_RSBRACKET "RSBRACKET"
#define TO_LSBRACKET "LSBRACKET"
#define TO_FUNCTION_DEF "FUNCTION"
#define TO_ERROR "ERROR"
#define TO_NULL "NULL"
#define TO_CALL_EXTERNAL "EXTERNALCOMMAND"
#define TO_CLASS "CLASS"
#define TO_BOOL "BOOLEANVALUE"

class Classes
{
public:
  std::string inheritList;
  std::string mode;
  Classes(std::string inheritList)
  {
    this->inheritList = inheritList;
    this->mode = "private";
  }
};

class Functions
{
public:
  std::vector<std::string> argslist;
  std::vector<std::string> executelist;
  Functions(std::vector<std::string> executelist, std::vector<std::string> argslist)
  {
    this->argslist = argslist;
    this->executelist = executelist;
  }
  ~Functions()
  {
    this->argslist.clear();
    this->executelist.clear();
  }
};

// VARIABLE SCOPES

class Level_Handler
{
public:
  bool isClass = false;
  std::string class_name;
  std::string mode = "private";
  std::any cl;

  Level_Handler(std::string className)
  {
    this->class_name = className;
  }
};

bool canBeInteger(float value)
{
  bool isInt = false;
  try
  {
    int value1 = int(value);
    return value1 == value;
  }
  catch (...)
  {
    return false;
  }
}
// ERROR CLASS
class Error
{
public:
  Error(std::string type_, std::string line, std::string file_, std::string details)
  {
    std::cout << type_ << "Error: [File " << file_ << " Line " << line << details << std::endl
              << "\nPress enter or return to close the application...";
    std::cin;
    exit(-1);
  }
};

// TOKEN CLASS THAT LEXER RETURNS
class Token
{
public:
  std::string type;
  std::string value;
  int level;
  std::string line;

  Token(std::string type, std::string value = NULL, int level = NULL, std::string line = "unknown")
  {
    this->type = type;
    this->value = value;
    this->level = level;
    this->line = line;
  }
  operator std::string() const
  {
    return this->type + " : " + this->value + " on line " + this->line;
  }
};

// MATHS CLASS
class mathsClass
{

public:
  std::vector<Token> argslist;
  int level;
  std::vector<std::string> bracketnums;

  mathsClass()
  {
  }
  ~mathsClass()
  {
    this->argslist.clear();
  }
  std::vector<Token> selfparse(std::vector<Token> args)
  {
    return this->parse(args);
  }
  std::vector<Token> parse(std::vector<Token> args)
  {
    this->argslist = args;
    try
    {
      for (int i = 0; i != this->argslist.size(); i++)
      {
        if (argslist[i].type() == "" || argslist[-1].type == TO_INTERNAL)
        {
          argslist.erase(argslist.begin() + i);
        }
      }
    }
    catch (...)
    {
    }

    int length = argslist.size();
    int i = 0;
    try {
      for (int r = 0; r != argslist.size(); r++) {
        if (argslist[r].type == TO_LBRACKET){
          level = argslist[r].level;
          bracketnums = {};
          int first = r;
          int last = 0;
          int count = r + 1;
          while (true) {
            if (argslist[count].type != TO_RBRACKET) {
              bracketnums.push_back(argslist[count]);
              count += 1;
            }
            else {
              if (argslist[count].level == level){
                last = count;
                std::vector<Token> value = this->selfparse(bracketnums);
                it = first;
                while(it != last) {
                  it = argslist.erase(it);
                  it++;
                }
                argslist[first] = value[0];
                break;
              }
            }
          }
        }
      }
    }
    catch (...) {}
    int state = 0;
    int i = 0;
    while (true){
      try{
        if (argslist[i].type == "INTERNALFUNCTION"){
          del argslist[i];
          int length -= 1;
          i -= 1.
        }
        if argslist[i].type == "SPECIALCHARACTERS"{
          if argslist[i].value == "="){
            del argslist[i] length -= 1 
            i -= 1
          }
          if state == 0 :
            if argslist[i].value == "*" : 
              result = int(argslist[i - 1].value) * int(argslist[i + 1].value);
              argslist[i] = Token(argslist[i - 1].type, result, argslist[i - 1].level)
                                                   del argslist[i + 1] del argslist[i - 1] length -= 2 i -= 1

                                                                                                            elif argslist[i]
                                                                                                                .value == "/" : result = argslist[i - 1].value / argslist[i + 1].value
                                                                                                                                                                     argslist[i] = Token(argslist[i - 1].type, result, argslist[i - 1].level)
                                                                                                                                             del argslist[i + 1] del argslist[i - 1] length -= 2 i -= 1 if state == 1 :

                  if argslist[i]
                      .value == "-" : result = argslist[i - 1].value - argslist[i + 1].value
                                                                           argslist[i] = Token(argslist[i - 1].type, result, argslist[i - 1].level)
                                                   del argslist[i + 1] del argslist[i - 1] length -= 2 i -= 1

                                                                                                            elif argslist[i]
                                                                                                                .value == "+" : result = argslist[i - 1].value + argslist[i + 1].value
                                                                                                                                                                     argslist[i] = Token(argslist[i - 1].type, result, argslist[i - 1].level)
                                                                                                                                             del argslist[i + 1] del argslist[i - 1] length -= 2 i -= 1

                  i += 1 continue except IndexError : if state == 0 : state = 1 i = 0 elif state == 1 : break except TypeError : Error("Type", argslist[i].line, fileControl.fileName, "invalid comparotor") return argslist

                                                                                                                                 class Struct : def
                                                                                                                                                __init__(self, keys, values, ) : this->keys = keys this->values = values this->struct
                  = this->makeStruct()

                        def
                        makeStruct(self) : res =
              {}

    if not len(this->keys) == len(this->values): return-1
    for i in range(len(this->keys)):
      res[this->keys[i]] = this->values[i]
    return res


// PARSER CLASSES
class BUILTIN_FUNCTION:
  def __init__(self,command,args):
    this->command = command
    this->args = args


class COMMENT:
  def __init__(self,command,args):
    this->command = "comment"
    this->args = NULL


FILE INPUT CLASS
class fileInput:
  def __init__(self, fileName = NULL):
    this->fileName = fileName

  def getFile(self):
    try:
      fileName = sys.argv[1]
    except:
      fileName = input("No file was found to be run. Please input one now: ")

      if (not os.path.exists(fileName)):
        std::cout << )
        std::cout << "INVALID FILE NAME")
        input("\nPress enter or return to close the application...")
        sys.exit()

    
    this->fileName = fileName
    
  
  def getFileContents(self, fileName =  NULL):
    
    if fileName == NULL:
      fileName = this->fileName
    else:
      this->fileName = fileName

    if not os.path.exists(fileName):
      return -1
    else:
      file_ = open(fileName, "rt")
      contents = file_.read()
      contents = str(contents).replace(r'\a\b\f\n\t','\a\b\f\n\t')
    
      if contents != "": 
        if contents[-1] != "\n": contents += "\n"
      return contents
    
ANYASIS CLASS THAT RETURNS RAW TOKENS

global cbracketnum,bracketnum,sbracketnum
sbracketnum = 0
cbracketnum = 0
bracketnum = 0
class Anyasis:

  def __init__(self): this->li = 0

  def make_command(self, text):
    global cbracketnum,bracketnum,sbracketnum

    isString = false
    
    isNum = false
    command_parts = []
    current_text_list = ""
    
    for i in range(len(text)):
      
      if text[i] == "[" and isString == false and isNum == false:
        sbracketnum += 1

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_LSBRACKET, text[i],sbracketnum ))

        
        continue
      if text[i] == "]" and isString == false and isNum == false:

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_RSBRACKET, text[i],sbracketnum ))
        sbracketnum -= 1
        continue;

          if (text[i] == "{" && isString == false && isNum == false)
          {
            cbracketnum += 1;

            if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
          current_text_list = ""
        
        command_parts.append(Token(TO_LCBRACKET, text[i],cbracketnum ))

        
        continue
      if text[i] == "}" and isString == false and isNum == false:

        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_RCBRACKET, text[i],cbracketnum ))
        cbracketnum -= 1
        continue
      if text[i] == "(" and isString == false and isNum == false:
        bracketnum += 1
        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum ))
          current_text_list = ""
        
        command_parts.append(Token(TO_LBRACKET, text[i],bracketnum ))
        
        continue
      if text[i] == ")" and isString == false and isNum == false:
        
        if current_text_list.strip() != "":
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
          current_text_list = ""


        command_parts.append(Token(TO_RBRACKET, text[i],bracketnum))
        bracketnum -= 1
        
        continue
      
      if text[i] == '"' and isString == true:
        isString = false
        command_parts.append(Token(TO_STRING, current_text_list,cbracketnum))
        current_text_list = ""
        continue
      elif text[i] == '"' and isString == false:
        isString = true

      else:
        
        if isString == false and text[i] == " " and current_text_list != "": 
          command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
          current_text_list = ""
        elif isString == false and text[i] == ",": 
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
            if isString == true:
              current_text_list += text[i]
            else:
              continue
          else:
            current_text_list += text[i]
    if current_text_list != "":
      command_parts.append(Token(TO_RT, current_text_list,cbracketnum))
      current_text_list = ""
    
    return command_parts

LEXER CLASS
class Lexer:
  
  def __init__(self,file):
    this->token_return_list = []
    this->li = 1
    this->file = file
    this->current_tok = NULL
      
  def make_tokens(self,tok_list):
    this->token_return_list = tok_list
    for i in range(len(tok_list)):
      level = tok_list[i].level
      
      if tok_list[i].type == TO_RT:
        tok_list[i].value = tok_list[i].value.replace(" ","")
        tok_list[i].line = this->li
      this->current_tok = tok_list[i]
      if (this->current_tok.type == TO_STRING)
              {
                this->current_tok.value = this->current_tok.value.replace("{}", "");
        this->current_tok.li = this->li
        this->current_tok.line = this->li
      if this->current_tok.type != TO_STRING:
        this->current_tok.line = this->li
        gettype,newvalue = convertToInt(this->current_tok.value)
        if gettype == true:
          this->token_return_list[i] = Token(TO_INT, newvalue,level, line = this->li)

        if this->current_tok.value in b_values:
          this->token_return_list[i] = Token(TO_BOOL, this->current_tok.value, level, line = this->li)
        
        if this->current_tok.value in functions:
          this->token_return_list[i] = Token(TO_FUNCTION, this->current_tok.value,level, line= this->li)
        if this->current_tok.value in externalfunctions:
          this->token_return_list[i] = Token("EXTERNAL_FUNCTION", this->current_tok.value,level, line= this->li)
      
        if this->current_tok.value in comparators:
          this->token_return_list[i] = Token(TO_COMPARATOR, this->current_tok.value,level,  line = this->li)
          continue
        if this->current_tok.value in keywords:
          this->token_return_list[i] = Token(TO_KEYWORD, this->current_tok.value,level,  line = this->li)
          continue
        if this->current_tok.value in characters:
          if this->current_tok.value != "":
            this->token_return_list[i] = Token(TO_SPECIALCHARACTERS, this->current_tok.value,level,  line = this->li)
        
        if this->current_tok.value not in functions:

          // this->current_tok.line = this->li
          this->token_return_list[i].line = this->li

    
    this->li +=1
    if DEBUG: std::cout << this->li)
    return this->token_return_list
  
        
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
            args_toks.append(this->selfparse(temp_toks))

          if len(temp_toks) == 0:
            args_toks.append(NULL)

          
          temp_toks = []
        
        else:
          temp_toks.append(toks[i])
    
    
    return args_toks
          
      
    
  def selfparse(self,toks):
    return this->parse(toks)
  def parsevalues(self,toks,toknum1):
    linetrue = false
    commandcontents = []
    toknum = toknum1
    level = toks[toknum].level
          
    if toks[toknum].type == TO_LBRACKET:
      
      level = toks[toknum].level
      toknum += 1
    while linetrue == false:
            if toks[toknum].level == NULL:
              toks[toknum].level = 0
            if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
            
              return commandcontents
              linetrue = true
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
                commandcontents.append(this->selfparse(functionline))

            
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
              
          
            if toks[toknum].type == TO_EOL:
              linetrue = true
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
        isDone = false
        while true:
          try:
            
            if toks[i].type == TO_KEYWORD and toks[i].value == "*/" or isDone:

              i+=1
              commandlist.append(BUILTIN_FUNCTION("comment", NULL))
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
        
        commandlist.append(BUILTIN_FUNCTION("comment", NULL))
          


      elif toks[i].value == "//":
        toknum = i+1
        commandlist.append(BUILTIN_FUNCTION("comment", NULL))
        while toks[toknum] != TO_EOL:
          toks[toknum].type =TO_INTERNAL

          if toks[i].type == TO_EOL:
            break

          try:
            temp = (toks[toknum])
            i += 1
            if DEBUG:
              std::cout << "COMMENTED: ", temp)
            del temp
          except:
            i -= 1
            return commandlist

      
      elif toks[i].type == TO_INTERNAL:
        continue


      elif toks[i].type == "EXTERNAL_FUNCTION":
        if toks[i].value in externalfunctions:
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          
          commandcontents = this->parsevalues(toks,toknum)
          
          
          commandlist.append(BUILTIN_FUNCTION(toks[i].value,commandcontents))

      elif toks[i].type == "BUILTIN_FUNCTION":

        if toks[i].value == "error":

          toknum = i +1
          linetrue = false

          tokens = []

          while not linetrue:

            if toks[toknum].type == TO_EOL:
              linetrue = true
            else:
              tokens.append(toks[toknum])
            toknum += 1
        
          commandlist.append(BUILTIN_FUNCTION("error", tokens))

      
        if toks[i].value == "this":

          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          tokens = this->parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("this", tokens))



        if toks[i].value == "class":

          inheritList = []
          linetrue = false
          executelist = []
          toknum = i + 1

          name = toks[toknum]

          toknum +=1
          
          if toks[toknum].type == TO_LBRACKET:
            level = toks[toknum].level
            
            toknum += 1 
            if toks[toknum].type != TO_LBRACKET:
              while linetrue == false:
                if toks[toknum].type != TO_RBRACKET: 
                                
                  inheritList.append(toks[toknum])
                  toknum += 1
                if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
                  linetrue = true
                  toknum+= 1

                  
              linetrue = false
              getbracket = true
              while getbracket == true:
                
                if toks[toknum].type == TO_LCBRACKET: 
                  level = toks[toknum].level
                  
                  while linetrue == false:
                      
                      executelist.append(toks[toknum])
                        
                      if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                        
                        linetrue = true
                        
                        executelist1 = this->selfparse(executelist)

                        commandlist.append((BUILTIN_FUNCTION("class",[name, inheritList,executelist1])))
                        getbracket = false
                        
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
          linetrue = false
          executelist = []
          toknum = i + 1
          if toks[toknum].type == TO_LBRACKET:
            level = toks[toknum].level
            
            toknum += 1 
            if toks[toknum].type != TO_LBRACKET:
              while linetrue == false:
                if toks[toknum].type != TO_RBRACKET: 
                                
                  conditionlist.append(toks[toknum])
                  toknum += 1
                if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
                  linetrue = true
                  toknum+= 1
                  
              linetrue = false
              getbracket = true
              while getbracket == true:
                
                if toks[toknum].type == TO_LCBRACKET: 
                  level = toks[toknum].level
                  
                  while linetrue == false:
                      
                      executelist.append(toks[toknum])
                        
                      if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                        
                        linetrue = true
                        
                        executelist1 = this->selfparse(executelist)
                        
                        commandlist.append((BUILTIN_FUNCTION("for",[conditionlist,executelist1])))
                        getbracket = false
                        
                        toknum = 0
                        break
                      toks[toknum] = Token(TO_INTERNAL)
                      toknum += 1
                toknum += 1
          toknum += 1  


        
        if toks[i].value == "if":
          
          conditionlist = []
          linetrue = false
          executelist = []
          toknum = i + 1
          if toks[toknum].type == TO_LBRACKET:
            level = toks[toknum].level
            
            toknum += 1 
            if toks[toknum].type != TO_LBRACKET:
              while linetrue == false:
                if toks[toknum].type != TO_RBRACKET: 
                                
                  conditionlist.append(toks[toknum])
                  toknum += 1
                if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
                  linetrue = true
                  toknum+= 1
                  
              linetrue = false
              getbracket = true
              while getbracket == true:
                
                if toks[toknum].type == TO_LCBRACKET: 
                  level = toks[toknum].level
                  
                  while linetrue == false:
                        
                      executelist.append(toks[toknum])
                      
                        
                      if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                        
                        
                        linetrue = true
                        
                        executelist1 = this->selfparse(executelist)
                        
                        
                        commandlist.append((BUILTIN_FUNCTION("if",[conditionlist,executelist1])))
                        getbracket = false
                        
                        toknum = 0
                        break
                      toks[toknum] = Token(TO_INTERNAL)
                      toknum += 1
                toknum += 1
          toknum += 1   
        
        if toks[i].value == "get":
          linetrue = false
          
          commandcontents = []
          toknum = i + 2
          varname = toks[toknum].value
          level = toks[toknum].level
          toknum += 1
          
          commandcontents = this->parsevalues(toks,toknum)
          //std::cout << varname,commandcontents,level)
          commandlist.append(BUILTIN_FUNCTION("get",[varname,commandcontents,level]))
        if toks[i].value == "delindex":
          linetrue = false
          
          commandcontents = []
          toknum = i + 2
          varname = toks[toknum].value
          level = toks[toknum].level
          toknum += 1
          
          commandcontents = this->parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("delindex",[varname,commandcontents,level]))
        if toks[i].value == "dict":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          level = toks[toknum].level
          
          if toks[toknum].type == TO_LSBRACKET:
            
            level = toks[toknum].level
            toknum += 1
          while linetrue == false:
                  if toks[toknum].level == NULL:
                    toks[toknum].level = 0
                  if toks[toknum].type == TO_RSBRACKET and toks[toknum].level == level:
                    
                    commandlist.append((BUILTIN_FUNCTION("dict",[commandcontents])))
                    linetrue = true
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
                      commandcontents.append(this->selfparse(functionline))

                  
                      
                  elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
                    if toks[toknum].type == TO_RT:
                      if toks[toknum].value != "":
                        commandcontents.append(toks[toknum])
                        pass
                    else:
                      commandcontents.append(toks[toknum])
                      
                      pass
                    
                
                  if toks[toknum].type == TO_EOL:
                    linetrue = true
                    toknum += 1
                    
                    
                    return commandcontents
                
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
        if toks[i].value == "array":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          level = toks[toknum].level
          
          if toks[toknum].type == TO_LSBRACKET:
            
            level = toks[toknum].level
            toknum += 1
          while linetrue == false:
                  if toks[toknum].level == NULL:
                    toks[toknum].level = 0
                  if toks[toknum].type == TO_RSBRACKET and toks[toknum].level == level:
                    
                    commandlist.append((BUILTIN_FUNCTION("array",[commandcontents])))
                    linetrue = true
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
                      commandcontents.append(this->selfparse(functionline))

                  
                      
                  elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
                    if toks[toknum].type == TO_RT:
                      if toks[toknum].value != "":
                        commandcontents.append(toks[toknum])
                        pass
                    else:
                      commandcontents.append(toks[toknum])
                      
                      pass
                    
                
                  if toks[toknum].type == TO_EOL:
                    linetrue = true
                    toknum += 1
                    
                    
                    return commandcontents
                
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
        if toks[i].value == "system":
          toknum = i+2
          md = toks[toknum-1].value

          name = this->selfparse(toks)
          std::cout << name)
          commandlist.append(BUILTIN_FUNCTION("system",[md, name]))
      
        if toks[i].value == "memset":
          // name =NULL
          // md = NULL
          // toknum = i+1
          // while toks[toknum].type != TO_LBRACKET:
          //   toknum +=1
          // toknum +=1
          // while toks[toknum].type != TO_RBRACKET:
            
          //   md = toks[toknum]

          //   toknum +=1
          //   if toks[toknum].type ==TO_SPECIALCHARACTERS and toks[toknum].value == ",":
          //     toknum +=1
          //   name =  toks[toknum]
          //   toknum +=1
          //   if toks[toknum].type == TO_RBRACKET:
          //     i -= 2
          //     break
            linetrue = false
            commandcontents = []
            toknum = i + 1
            varname = toks[toknum].value
            commandcontents = this->parsevalues(toks,toknum)

            commandlist.append(
              BUILTIN_FUNCTION("memset", commandcontents)
            )
          
        if toks[i].value == "memread":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)

          commandlist.append(
            BUILTIN_FUNCTION("memread", commandcontents)
          )
        
        if toks[i].value == "loc":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)

          commandlist.append(
            BUILTIN_FUNCTION("loc", commandcontents)
          )
        

            
        if toks[i].value == "function":
          argslist = []
          linetrue = false
          executelist = []
          toknum = i + 1
          name = toks[toknum]
          argslist = []
          linetrue = false
          getbracket = true
          while getbracket == true:
            
            if toks[toknum].type == TO_LBRACKET: 
              level = toks[toknum].level
              toknum += 1
              while linetrue == false:
                  
                    
                  if toks[toknum].type == TO_RT:
                    argslist.append(toks[toknum])
                  
                    
                  if toks[toknum].type == TO_RBRACKET and toks[toknum].level == level:
                    
                    
                    
                    linetrue = true
                    
                    
                    
                    
                    
                    getbracket = false
                    
                    
                    break
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
            toknum += 1
          getbracket = true
          
          linetrue = false
          
          while getbracket == true:
            
            if toks[toknum].type == TO_LCBRACKET: 
              level = toks[toknum].level
              
              while linetrue == false:
                  
                    
                    
                  executelist.append(toks[toknum])
                  
                    
                  if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                    
                    
                    
                    linetrue = true
                    
                    executelist1 = this->selfparse(executelist)
                    
                    
                    commandlist.append((BUILTIN_FUNCTION("function",[name,executelist1,argslist])))
                    getbracket = false
                    
                    toknum = 0
                    break
                  toks[toknum] = Token(TO_INTERNAL)
                  toknum += 1
            toknum += 1
        if toks[i].value == "del":
          linetrue = false
          
          commandcontents = []
          toknum = i + 1
          varname= toks[toknum].level
          level = toks[toknum].level
          
          
          commandcontents = this->parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("del",[varname,commandcontents,level]))   
        if toks[i].value == "var":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          level = toks[toknum].level
          toknum += 1
          
          commandcontents = this->parsevalues(toks,toknum)
          
          commandlist.append(BUILTIN_FUNCTION("var",[varname,commandcontents,level]))
              
            


        if toks[i].value == "ptr":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          commandcontents.append(toks[toknum])
          toknum += 1
                

          while linetrue == false:
            
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
                commandcontents.append(this->selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                pass
              
            if toks[toknum].type == TO_EOL:
              linetrue = true
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("ptr",commandcontents))
              
              break
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

        
        if toks[i].value == "savedVar":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          toknum += 1
                
          

          while linetrue == false:
            
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
                commandcontents.append(this->selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
              
          
            if toks[toknum].type == TO_EOL:
              linetrue = true
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("savedVar",[varname,commandcontents]))
              
              break
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1
        
        if toks[i].value == "import":
          linetrue = false
          commandcontents = []
          toknum = i + 1

          varname = toks[toknum].value
          toknum += 1
          level = toks[toknum].level
          
          while linetrue == false:
            
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
                commandcontents.append(this->selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                pass
          
            if toks[toknum].type == TO_EOL:
              linetrue = true
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("import",[varname,commandcontents]))
              
              break
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

        if toks[i].value == "extern":
          linetrue = false
          commandcontents = []
          toknum = i + 1

          varname = toks[toknum].value
          toknum += 1
          level = toks[toknum].level
          
          while linetrue == false:
            
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
                commandcontents.append(this->selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                pass
          
            if toks[toknum].type == TO_EOL:
              linetrue = true
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("extern",[varname,commandcontents]))

              break
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

          

        if toks[i].value == "call":
          name = toks[i + 1].value
          argslist = this->parsevalues(toks,i+2)
          
          commandlist.append(BUILTIN_FUNCTION("call",[name,argslist]))
          
        if toks[i].value == "savedVarDelete":
          
          std::cout << "hello world!hi")

          lineToks = []
          toknum = i + 1
          
          std::cout << toknum)

          while toks[toknum].type != TO_EOL:
            lineToks.append(toks[toknum])
            toknum += 1

          std::cout << lineToks)
          commandlist.append(BUILTIN_FUNCTION("savedVarDelete",[]))
            
          

        if toks[i].value == "while":
          conditionlist = []
          linetrue = false
          executelist = []
          toknum = i + 2
          if toks[toknum].type != TO_LBRACKET:
            level = toks[toknum].level
            while linetrue == false:
              if toks[toknum].type != TO_RBRACKET:            
                conditionlist.append(toks[toknum])
                toknum += 1
              if toks[toknum].type == TO_RBRACKET:
                linetrue = true
                toknum+= 1
            linetrue = false
            linetrue = false
            getbracket = true
            while getbracket == true:
              
              if toks[toknum].type == TO_LCBRACKET: 
                level = toks[toknum].level
                
                while linetrue == false:
                    
                      
                      
                    executelist.append(toks[toknum])
                    
                      
                    if toks[toknum].type == TO_RCBRACKET and toks[toknum].level == level:
                      
                      
                      
                      linetrue = true
                      
                      
                      getbracket = false
                      
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
            std::cout << "ERROR: NEED 3 values")
          executelist = this->selfparse(executelist)

          commandlist.append(BUILTIN_FUNCTION("while",[
            [l,c,r],
            [executelist]
            ]))

        if toks[i].value == "openfile":
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("openfile",[varname,commandcontents]))

        if toks[i].value == "attach":
          
          linetrue = false
          commandcontents = []
          toknum = i + 2
          varname = toks[toknum].value
          num = NULL


          for x in toks[toknum:]:
            if x.type == TO_RBRACKET:
              num = toks.index(x)
              break

          if num == NULL: 
            Error("Syntax", toks[toknum-2].li, fileControl.fileName, "Unmatched Bracket")
          commandcontents = (this->parseargs(toks[toknum:num]))

          
          
          commandlist.append(BUILTIN_FUNCTION("attach",[varname,commandcontents]))
        
        if toks[i].value == "write":
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)
          
          
          commandlist.append(BUILTIN_FUNCTION("write",[varname,commandcontents]))

        if toks[i].value == "size":
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("size",[varname,commandcontents]))
        if toks[i].value == "type":
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("type",[varname,commandcontents]))
              
              
            
          
      if toks[i].value == "appendto":
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)
          
          

          
          commandlist.append(BUILTIN_FUNCTION("appendto",[varname,commandcontents]))
      if toks[i].value == "input":
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum) 
          commandlist.append(BUILTIN_FUNCTION("input",[varname,commandcontents]))
              
              
      
      if toks[i].value == "return":
          
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          
                
          

          while linetrue == false:
            
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
                commandcontents.append(this->selfparse(functionline))
                
            elif toks[toknum].type != TO_FUNCTION and toks[toknum].type != TO_EOL:
              if toks[toknum].type == TO_RT:
                if toks[toknum].value != "":
                  commandcontents.append(toks[toknum])
                  pass
              else:
                commandcontents.append(toks[toknum])
                
                pass
              
          
            elif toks[toknum].type == TO_EOL:
              linetrue = true
              toknum += 1
              
              commandlist.append(BUILTIN_FUNCTION("return",[varname,commandcontents]))
              
              break
          
            toks[toknum] = Token(TO_INTERNAL)
            toknum += 1

      if toks[i].value == "new":
        linetrue = false
        commandcontents = []
        toknum = i + 1
        varname = toks[toknum].value
        commandcontents = this->parsevalues(toks,toknum)
        commandlist.append(BUILTIN_FUNCTION("new",[varname,commandcontents]))
                                              
      if toks[i].value == "string":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)
          commandlist.append(BUILTIN_FUNCTION("string",[varname,commandcontents]))
              
              
      if toks[i].value == "int":
          linetrue = false
          commandcontents = []
          toknum = i + 1
          varname = toks[toknum].value
          commandcontents = this->parsevalues(toks,toknum)
          commandlist.append(BUILTIN_FUNCTION("int",[varname,commandcontents]))
      // if toks[i].value == "struct":
      
      //   end = false
      //   commandcontents = ""    
      //   variablenames = []

      //   toknum += 1
      //   structName = toks[toknum]
      //   toknum += 1

      //   if toks[toknum] == TO_EQUALS:
      //     toknum += 1
    
      //   if toks[toknum] == TO_LBRACKET:
      //     toknum += 1

      //   while end == false:
      //     pass

      if toks[i].type == "SPECIALCHARACTERS":
        if toks[i].value == "#":
          continue
      
      if toks[i].type == TO_KEYWORD and toks[i].value in ["public","inherit","private"]:
        commandlist.append(BUILTIN_FUNCTION("ACCESS_SPECIFIER",toks[i]))          
      
    
    return commandlist

INTERPRETER
class Interpreter:
  global variables,externalfunctions
  def __init__(self):
    pass
  def functionrun(self,executelist,variableslist):
    global variables
    if len(variableslist) != 0:
      for key,item in variableslist.items():
        variables[1][key] = item
    
    return this->selfrun(executelist)
  def selfrun(self,command_list, classAppend = NULL):
      return this->run(command_list,1, classAppend)
  
  def getvar(self,name,level):
      global variables
      returnvalue = NULL
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
    std::cout << argslist)

    for i in range(len(argslist)):
      if argslist[i].type == TO_COMPARATOR:

        LHS = argslist[i-1]
        RHS = argslist[i+1]
        COM_ = argslist[i]

        if LHS.type == TO_RT:
          LHS = this->getvar(LHS.value, LHS.level)
          std::cout << "LHS:", LHS)
          if LHS == NULL:
            Error("Name",LHS.line, fileControl.fileName, f"Variable {LHS.value} is not defined")

        if RHS.type == TO_RT:
          RHS = this->getvar(RHS.value, RHS.level)
          std::cout << "RHS:", RHS)
          if RHS == NULL:
            Error("Name",RHS.line, fileControl.fileName, f"Variable {RHS.value} is not defined")

        COM = COM_.value
        
        if COM == "==":
          if LHS.value == RHS.value:
            return true
          else:
            return false
        
        if COM == "===":
          if LHS.value == RHS.value and LHS.type == RHS.type:
            return true
          else:
            return false
        
        if COM == "!=":
          if LHS.value != RHS.value:
            return true
          else:
            return false
        
        if COM == "!==":
          if LHS.value != RHS.value and LHS.type != RHS.type:
            return true
          else:
            return false

        if COM == ">":
          if not ( LHS.type in [TO_INT, TO_FLOAT] and RHS.type in [TO_INT, TO_FLOAT]):
            Error("Comparator", COM_.line, fileControl.fileName, "Comparator > is not valid on types that are not INT or FLOAT")
          if LHS.value == RHS.value:
            return true
          else:
            return false

  def parsevalues(self,values):
    assignvalue = []
    
    for o in range(len(values)):
            
      value = values[o]
      
      if isinstance(value,int) == false:
        
        if isinstance(value,list):
          
          if isinstance(value[0],BUILTIN_FUNCTION):
            
              thing = this->selfrun([value[0]])
              assignvalue.append(thing)
              continue
        else
        {
          if value.type == TO_RT:
            
            variable = this->getvar(value.value,value.level)
            
            if variable == NULL:
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


  
  def run(self,command_list1,mode, classAppend = NULL):
    md = mode
    command_list = command_list1
    global fvariables,variables
    store_list = command_list
    
    if DEBUG:
      for i in range(len(command_list)):
        std::cout << command_list[i].command,end = " ")
        std::cout << command_list[i].args,end = " ")
        std::cout << )
    for i in range(len(command_list)):
      current_command = command_list[i]
      
      if current_command.command in externalfunctions:
        
          variables,returner = runners[externalfunctions[current_command.command]].run(current_command,variables)
        
          if returner != NULL and md == 1:
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
            assign.append(this->parsevalues(tempargslist[i]))
            assign[i] = assign[i][0]
        if md != 0:
          
          return Token(TO_LIST,assign,values[0].line)
        
      if current_command.command == 'input':
        values = current_command.args[1];

          output = this->parsevalues(values);

          returner = input(output[0].value)
              returner = Token(output[0].type, returner, output[0].level) if md == 0 : pass else : return returner if current_command.command == 'int' : values = current_command.args[1] output = this->parsevalues(values)[0] output.type = TO_INT
          try : output.value = int(output.value)
        except:
          Error("Type", output.line, fileControl.fileName, "number of args for function does not match required number")
        if md == 1:
          return output
      if current_command.command == 'string':
        values = current_command.args[1]
        output = this->parsevalues(values)[0]
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



        if classAppend != NULL:

          
          classAppend.cl[classAppend.class_name].inherit_list[classAppend.cl[classAppend.class_name].mode][functionAssign.value] = declaredfunctions[functionTemplate.value]
        
        else:
          declaredfunctions[functionAssign.value] = declaredfunctions[functionTemplate.value]

        if deleteTemplate.value == "1":
          del declaredfunctions[functionTemplate.value]



      if current_command.command == 'write':
        values = current_command.args[1]
        
        output = this->parsevalues(values)
        
        //DONT TOUCH YOU IDIOTS THIS IS FOR WRITE COMMAND.
        std::cout << output[0].value)

      if current_command.command == 'openfile':
        values = current_command.args[1]
        std::cout << values)
        output = this->parsevalues(values)

        
        
        std::cout << output[0].value)
      if current_command.command == 'size':
        values = current_command.args[1]
            try : output = this->parsevalues(values)
        
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
          if (arg.type != TO_SPECIALCHARACTERS)
              {
                output.append(arg)
              }
          else
          {
            if arg
              .value != "," : output.append(arg)
          }
        }
        output = this->parsevalues(output);
        if (isinstance(variables[assignlevel][name.value].value, list) == false)
        {
          Error("Type", assignlevel, fileControl.fileName, "variable is not list");
          try
          {
            variables[assignlevel][name.value].value.append(output[0]);
          }
          catch (...)
          {
            Error("Undefined", assignlevel, fileControl.fileName, "variable is not defined");
          }

          if current_command
            .command == 'get' :

                name = current_command.args[0]

                       args = current_command.args[1].copy()

            try:
          for i in range(len(args)):
            if args[i].type == TO_LSBRACKET or args[i].type == TO_RSBRACKET:
              del args[i]
        except:
          pass
        args = this->parsevalues(args)[0]
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

              if name
                in classes:
                try : tmp
                  = classes[name].inherit_list["public"][args.value] if isinstance (tmp, Token) : returner = tmp
                      elif
                      isinstance(tmp, Functions) : // std::cout << "wir haben eine funktion")
                                                   returner = this->functionrun(tmp.executelist, [])
                                                                  except : Error("Class", args.line, fileControl.fileName, "field does not exist, did you put the variable in public?")

                                                                               elif args.value in
                                                                               globals()["saved_variables"]:
                  try : returner
                    = globals()["saved_variables"][args.value] except : Error("Name", args.line, fileControl.fileName, "saved variable does not exist.")

                                                                            else:
                    try : returner
                      = variables[assignlevel][name].value[args.value] except : Error("Name", args.line, fileControl.fileName, "variable is not defined")

                                                                                    except IndexError : Error("Index", args.line, fileControl.fileName, "list index out of range")
                                                                                                            except KeyError : Error("Key", args.line, fileControl.fileName, "unknown invalid key")

                                                                                                                                  if md == 1 : return returner if current_command.command == 'dict' : name = current_command.command
                                                                                                                                                                                                                 args = current_command.args[0].copy()
                                                                                                                                                                                                                            assign = {} tempname = [] tempassign = []

                          for i in range(len(args)) :
                          std::cout << args[i]) if args[i]
                          .type != "RT" and
                          args[i]
                          .value != ":" :
                          tempname.append(args[i])

                              else :

                          for o in range(len(args) - i) :

                          std::cout
                          << "2", args[o + i]) if args[o + i]
                          .type != TO_SPECIALCHARACTERS and
                          args[o + i]
                          .value != "," :
                          tempassign.append(args[o + i])

                              else
                      {

                        // tempname=this->parsevalues(tempname)

                        // tempassign = this->parsevalues(tempassign)

                        assign[tempname[0]] = Token(TO_DICT, tempassign, tempassign[0].level);
                      }
          std::cout << "RETURNER" << assign;
          return assign;
          if current_command
            .command == 'delindex' : name = current_command.args[0] args = current_command.args[1].copy()

            try:
          for i in range(len(args)):
            if args[i].type == TO_LSBRACKET or args[i].type == TO_RSBRACKET:
              del args[i]
        except:
          pass
        args = this->parsevalues(args)[0]
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

            try : dellist = variables[assignlevel][name].value
          
          del dellist[args.value]
          variables[assignlevel][name].value[args.value] = dellist
        except IndexError:
          Error("Index", args.line, fileControl.fileName, "list index out of range")
        except KeyError:
          Error("Key", args.line, fileControl.fileName, "invalid key")
        if md == 1:
          return returner
        

      if current_command.command == "for":
        md = NULL
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
          std::cout << start, " ", stop, " ", increment)

        if md == "auto":
          // std::cout << "AUTO")

          //start, stop , value

          //auto   x     "hello world"
          //auto   x     y
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
            this->selfrun(code)
            
        if md == "std":

          if start.type == TO_INT:
            c1 = start.value
          elif start.type == TO_RT:
              try : c1 = this->getvar(start.value.strip(), start.level)
              c1 = c1.value
            except: 
              c1 = NULL
              std::cout << "ERROR")
        
          if stop.type == TO_INT:
            c2 = stop.value
          elif stop.type == TO_RT:
                try : c2 = this->getvar(stop.value.strip(), stop.level)
              c2 = c2.value
            except: 
              c2 = NULL
              std::cout << "ERROR")
        
          if increment.type == TO_INT:
            c3 = increment.value
          elif increment.type == TO_RT:
                  try : c3 = this->getvar(increment.value.strip(), increment.level)
              c3 = c3.value
            except: 
              c3 = NULL
              std::cout << "ERROR")


          for i in range(c1, c2, c3):
            this->selfrun(code)

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
      
      if current_command.command == 'var':// interprit the raw token as variables and get the values. something to do tomoz. :) i want to die btw

        values = current_command.args[1];

          assignvalue = this->parsevalues(values)

                            assignlevel = current_command.args[2] level = current_command.args[2] for o in range(level) :

              if o == level :
              assignlevel = level break if len (variables[o]) != 0 :
              if current_command.args[0] in list(variables[o]) :

              assignlevel = o break

              else :
              assignlevel -= 1

                             if classAppend != NULL :
              classAppend.cl[classAppend.class_name].inherit_list[classAppend.mode][current_command.args[0]] = assignvalue[0]

              else :
              variables[assignlevel][current_command.args[0]] = assignvalue[0] if (current_command.command == "savedVar") :

              var_name = current_command.args[0] var_val = current_command.args[1][1].value

                                                               globals()["saved_variables"][var_name] = Token(TO_RT, var_val)

                  if (current_command.command == "savedVarDelete") :

              var_name = current_command.args[0]

                         std::cout
                         << var_name) if var_name == "__all__" :
              saved_variables = {} else:
          try : del saved_variables[var_name]
          except:
            pass


      if current_command.command == 'comment':
        std::cout << '', end = '')
        
      
      if current_command.command == 'roar':
        temp = current_command.args
        output = temp[0]
        varnames = temp[1]
        if "{}" in temp[0]:
          
          for i in range(len(temp[1])):
            
            output = output.replace("{}",str(variables.get(varnames[i])),1)
        output = output.upper()
        std::cout << output)
      
      if current_command.command == "random":
        args = current_command.args
        int1,int2 = args[0],args[1]
        if md == 1:
          return Token(TO_INT,random.randint(int1,int2))
      if current_command.command == 'return':
        
        values = this->parsevalues(current_command.args[1])
        //values = current_command.args[1]
        if md == 1:
          return values[0]
      
      if current_command.command == "type":

        args = this->parsevalues(current_command.args[1])[0]
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
        std::cout << argslist)
        for arg in argslist:
          if isinstance(arg,list):
            tempargslist[argnum].append(this->selfrun(arg))
            continue
          if arg.value != ",":
            tempargslist[argnum].append(arg)
          else:
            if arg.value == ",":
              tempargslist.append([])
              argnum += 1
        argslist = tempargslist
        std::cout << tempargslist)
        funcvariables = {}
        if len(calledfunctionargs) > 0:
          if len(calledfunctionargs) != len(argslist):
            Error("UserFunction", calledfunctionargs[0].line, fileControl.fileName, "number of args for function does not match required number")
          
          for i in range(len(argslist)):
            if argslist[i] == []:
              
                Error("UserFunction", calledfunctionargs[0].line, fileControl.fileName, f"required arg {calledfunctionargs[i].value} is empty");
          argslist[i] = this->parsevalues(argslist[i]);
          funcvariables[calledfunctionargs[i].value] = argslist[i][0];

          returner = this->functionrun(runner, funcvariables);

          // argslist = this->parsevalues(argslist)

          if (returner != NULL)
          {
            return returner;
          }

          if (current_command.command == "extern")
          {

            cmd = current_command.args[0];
            args = current_command.args[1];

            if (not cmd.strip() in imported_functions)
            {
              Error("Import", "NULL", "NULL", "NULL");

              external_cmd = imported_functions[cmd] external_cmd(args)
            }
            if (current_command.command == "this")
            {

              if (current_command.args[0].type == TO_SPECIALCHARACTERS and current_command.args[0].value == "->")
              {

                runner_list = current_command.args [1:]

                              this->selfrun(runner_list[0], classAppend = variables[current_command.args[0].level - 1]["__internal"])
              }
            }
            if (current_command.command == "class")
            {

              variables[current_command.args[0].level]["__internal"].class_name = current_command.args[0].value

                                                                                      variables[current_command.args[0].level]["__internal"]
                                                                                          .isClass = true

                  uninitialized_classes[current_command.args[0].value] = current_command.args[0].level

                                                                             variables[current_command.args[0].level]["__internal"]
                                                                                 .cl[current_command.args[0].value] = Classes({
                                                                                                                        "public" : {},
                                                                                                                        "inherit" : {},
                                                                                                                        "private" : {}
                                                                                                                      })

                                                                                                                          this->selfrun(current_command.args[2])
            }

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
              
              conditions[i] = this->getvar(conditions[i].value,conditions[i].level)
              
        o = 0
        
        length = len(conditions)
        while length > 1 and o < length:
          
          if conditions[o].type == "COMPARATOR":
            
            if conditions[o].value == "==":
              
              if conditions[o-1].value == conditions[o+1].value:
                conditions[o] = true
                del conditions[o+1]
                del conditions[o-1]
                length -= 2
                o -= 1
                continue
              else:
                  conditions[o] = false
                  del conditions[o+1]
                  del conditions[o-1]
                  length -= 2
                  o -= 1
                  continue
            if conditions[o].value == "!=":
              
              if conditions[o-1].value != conditions[o+1].value:
                conditions[o] = true
                del conditions[o+1]
                del conditions[o-1]
                length -= 2
                o -= 1
                continue
              else:
                conditions[o] = false
                del conditions[o+1]
                del conditions[o-1]
                length -= 2
                o -= 1
                continue
          o += 1
        
        if conditions[0] == true:
          
          this->selfrun(execute)
        
      if current_command.command == "function":
        args = current_command.args
        name = args[0]
        execute = args[1]
        argslist = args[2]

        if classAppend != NULL:
          classAppend.cl[classAppend.class_name].inherit_list[classAppend.mode][name.value] = Functions(execute, argslist)

        else:
          declaredfunctions[name.value] = Functions(execute,argslist)


      if current_command.command == "loc":

        var = this->getvar(current_command.args[0].value, current_command.args[0].level)

        if md == 0:
          pass
        if md == 1:
          return Token(TO_INT, hex(id(var)))

      
      if current_command.command == "system":
        OSmode = current_command.args[0]
        if OSmode == 0:
          //return an exit status
          returner = Token(TO_INT,os.system(current_command.args[1]))
        
        if OSmode == 1:
          //return the command output
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
                        except : pass

                                 if condition[0]
                                     .type != TO_STRING and condition[0].value in variables : pass

                                                                                              while (1)
                {
                  res = this->checkBooleanCondition(condition);
                  std::cout << res;
                  if (res)
                    this->selfrun(code);
                  else
                    break;
                }
            command_list = store_list;

            // END OF CLASSES AND COMMANDS
            Settings = lambda f : json.load(open(f))
                                      settings = Settings("settings.json")

            try :

                /*
                for (int i = 0; i < 2000; i++){
                  variables[i] = {"__internal":Level_Handler()
                }
                */
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

              try : t = text[i][-1]
    except: continue
    if text[i][-1] == " ": 
      text[i] = removeLast(text[i])


  std::cout << ) //newline before we start.
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
    std::cout << variables)
    std::cout << declaredfunctions)
    """DEBUG INFORMATION"""

    for i in range(len(commands)):
      std::cout << commands[i].command,end = " ")
      std::cout << commands[i].args,end = " ")
      std::cout << )
  saved_handler.writeDict(saved_variables)
  input("\nPress enter or return to close the application...")

except Exception as e:
  std::cout << fsefhkjshkfjs)
  today = date.today()
  f = open("log.txt","a")

  exc_type, exc_obj, exc_tb = sys.exc_info()
  fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
  //'std::cout << exc_type, fname, exc_tb.tb_lineno)
  
  std::cout << 'Uncaught Error! Code: << type(e)._name__ << "Message: " << str(e);
  
  if (settings["autoDumpError"] == false)
                {
                  dump = input("Dump Error to log.txt? y/n: ");
                }
  else
    dump = "y"

  if dump.lower() == "y":
    f.write("Error: " + str(today) + " \n" + str(exc_type) + " " +  str(fname) + " line:" +  str(exc_tb.tb_lineno))
    f.write(' Code: {c}, Message: {m}'.format(c = type(e).__name__, m = str(e)) + "\n")


    //f.write(f'Error Type: {type(e).__name__,}, Message: {str(e)} When attempting to run file: {fileHandler.fileName}')

  else:
    pass
  f.close()
    
    
// we used some memory, so let's give it back

globals__ = globals()
keys = list(globals__.keys())
for y in range(len(globals__)):
  try:
    if keys
  [y] != "globals__" : del(globals__[keys[y]]) else : continue except IndexError : break del globals__, keys, y
