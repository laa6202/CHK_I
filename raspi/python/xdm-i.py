#!/usr/bin/python3
import datetime
import random
import pygame,sys
from pygame.locals import *
import os

FPS = 2
WINWIDTH=1200
WINHEIGHT=600
FNLOGO = 'logo.png'
FNTITLE = 'Title.png'
FNSYSOK = 'sysOK.png'
FNSYSWARNING = 'sysWarning.png'
FNSYSERROR  = 'sysError.png'
FNRPM = 'rpm.png'
FNOIL = 'oil.png'
FNTEM = 'tem.png'
FNXXX = 'xxx.png'



#           R   G   B
GRAY	= (100,100,100)
NAVYBLUE= ( 60, 60,100)
WHITE	= (255,255,255)
RED     = (255,  0,  0)
GREEN 	= (  0,255,  0)
BLUE	= (  0,  0,255)
YELLOW	= (255,255,  0)

BGCOLOR = WHITE

def main():
    global FPSCLOCK
#    global DIS
    fnValue = 'rec2.dat'
    stSYS = 0
    rot = 3200
    tem = 85.07
    oil = 1234.56
    xxx = 'AA'
    stDirPic = PicDirInit()
    DIS=DisInit()
    FPSCLOCK = pygame.time.Clock()



    while True:
        for event in pygame.event.get():
            if event.type == QUIT or (event.type == KEYUP and event.key == K_ESCAPE):
                pygame.quit()
                sys.exit()
        DIS.fill(WHITE)
        GetValue(fnValue)
        ShowAll(stDirPic)
        pygame.display.update()
        FPSCLOCK.tick(FPS)


def GetValue(fnValue) :
    global stSYS
    global rot
    global tem
    global oil
    global xxx
    stSYS = 0
    rot = 3200
    tem = 85.07
    oil = 1234.56
    xxx = 'AA'
    fd = open(fnValue,'r')
    s = fd.readline()
    s = fd.readline()
    s = fd.readline()
    s = fd.readline()
    print(str(float(s)))
    fd.close()
    


def ShowAll(stDirPic):
    ShowLogo(stDirPic,(0,0))
    ShowTitle(stDirPic,(300,0))
    pygame.draw.line(DIS,NAVYBLUE,(10,110),(WINWIDTH-10,110),3)
    ShowSysStatus(stDirPic,stSYS,(0,120))
   # ShowTime(BLUE,(500,128))
    ShowRPM(stDirPic,rot,(0,160))
    ShowOil(stDirPic,oil,(0,260))
    ShowTEM(stDirPic,tem,(0,360))
    ShowXXX(stDirPic,xxx,(0,460))


def PicDirInit():
    stDirMain = sys.path[0]
    stDirPic = stDirMain + '/pic'
    #print(stDirPic)
    return stDirPic


def ShowLogo(stDirPic,pos):
    fnLogo = stDirPic + '/' + FNLOGO
    #print(fnLogo,type(fnLogo),pos)
    surLogoSrc = pygame.image.load(fnLogo)
    surLogoDst = pygame.transform.scale(surLogoSrc,(200,100))
    global DIS
    DIS.blit(surLogoDst,pos)    


def ShowTitle(stDirPic,pos):
    fnTitle = stDirPic + '/' + FNTITLE
    surTitle = pygame.image.load(fnTitle)
    global DIS
    DIS.blit(surTitle,pos)
    #print(objFont)


def ShowSysStatus(stDirPic,flag,pos):
    if flag == 0 :
        fnSysStatus = stDirPic + '/' + FNSYSOK
    elif flag == 1 :
        fnSysStatus = stDirPic + '/' + FNSYSWARNING
    elif flag == 2 :
        fnSysStatus = stDirPic + '/' + FNSYSERROR
#    print(fnSysStatus)
    surSysStatus = pygame.image.load(fnSysStatus)
    global DIS
    DIS.blit(surSysStatus,pos)


def ShowTime(color,pos):
    stNow = GetStrTime()
#    print(type(stNow),stNow)
    stFont = pygame.font.get_default_font()
    objFont = pygame.font.SysFont(stFont,32,False)
#    print(objFont.size(stNow))
    surTime = objFont.render(stNow,True,color)
    global DIS
    DIS.blit(surTime,pos)


def ShowRPM(stDirPic,rpm,pos):
    fnRPM = stDirPic + '/' + FNRPM
    surRPM = pygame.image.load(fnRPM)
    global DIS
    DIS.blit(surRPM,pos)

    stFont = pygame.font.get_default_font()
    objFont = pygame.font.SysFont(stFont,100,False) 
    surRPM = objFont.render(str(rpm),True,YELLOW)
    pos2 = list(pos)
    pos2[0] += 420
    pos2[1] += 0
    DIS.blit(surRPM,pos2)


def ShowOil(stDirPic,oil,pos) :
    fnOIL = stDirPic + '/' +FNOIL
    surOIL = pygame.image.load(fnOIL)
    global DIS
    DIS.blit(surOIL,pos)

    stFont = pygame.font.get_default_font()
    objFont = pygame.font.SysFont(stFont,100,False)
    surOIL = objFont.render(str(oil),True,GREEN)
    pos2 = list(pos)
    pos2[0] += 420
    pos2[1] += 0
    DIS.blit(surOIL,pos2)
    


def ShowTEM(stDirPic,tem,pos):
    fnTEM = stDirPic + '/' +FNTEM
    surTEM = pygame.image.load(fnTEM)
    global DIS
    DIS.blit(surTEM,pos)

    stFont = pygame.font.get_default_font()
    objFont = pygame.font.SysFont(stFont,100,False)
    if tem > 69 :
        color = RED
    elif tem > 60 :
        color = YELLOW
    else :
        color = GREEN
    surTEM = objFont.render(str(tem),True,color)
    pos2 = list(pos)
    pos2[0] += 420
    pos2[1] += 0
    DIS.blit(surTEM,pos2)
    

def ShowXXX(stDirPic,xxx,pos) :
    fnXXX = stDirPic + '/' + FNXXX
    surXXX = pygame.image.load(fnXXX)
    global DIS
    DIS.blit(surXXX,pos)


def DisInit():
    pygame.init()
    #DIS = pygame.display.set_mode((WINWIDTH,WINHEIGHT),pygame.FULLSCREEN|pygame.HWSURFACE)
    global DIS
    DIS = pygame.display.set_mode((WINWIDTH,WINHEIGHT))
    pygame.display.set_caption("XDM_I")
    DIS.fill(BGCOLOR)
    return DIS

 
def GetStrTime():
    objNow = datetime.datetime.now()
    stNow = objNow.strftime('%Y-%m-%d %H:%M:%S')
    return stNow


if __name__ == '__main__':
    main()



    
