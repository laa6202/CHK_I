#!/usr/bin/python3

import datetime
import random
import pygame,sys
from pygame.locals import *

FPS = 2
WINWIDTH=720
WINHEIGHT=480
FNLOGO = 'logo.png'
FNTITLE = 'Title.png'
FNSYSOK = 'sysOK.png'
FNSYSWARNING = 'sysWarning.png'
FNSYSERROR  = 'sysError.png'
FNRPM = 'rpm.png'
FNTEM = 'tem.png'


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
    global FPSCLOCK,DIS
    stDirPic = PicDirInit()
    DIS=DisInit()
    FPSCLOCK = pygame.time.Clock()



    while True:
        for event in pygame.event.get():
            if event.type == QUIT or (event.type == KEYUP and event.key == K_ESCAPE):
                pygame.quit()
                sys.exit()
        DIS.fill(WHITE)
        ShowAll(stDirPic)
        pygame.display.update()
        FPSCLOCK.tick(FPS)


def ShowAll(stDirPic):
    ShowLogo(stDirPic,(0,0))
    ShowTitle(stDirPic,(100,0))
    pygame.draw.line(DIS,NAVYBLUE,(10,110),(710,110),3)
    ShowSysStatus(stDirPic,0,(0,120))
    ShowTime(BLUE,(500,128))
    ShowRPM(stDirPic,(0,160))
    ShowTEM(stDirPic,(-20,320))



def PicDirInit():
    stDirMain = sys.path[0]
    stDirPic = stDirMain + '/pic'
    #print(stDirPic)
    return stDirPic


def ShowLogo(stDirPic,pos):
    fnLogo = stDirPic + '/' + FNLOGO
    #print(fnLogo,type(fnLogo),pos)
    surLogoSrc = pygame.image.load(fnLogo)
    surLogoDst = pygame.transform.scale(surLogoSrc,(100,100))
    DIS.blit(surLogoDst,pos)    


def ShowTitle(stDirPic,pos):
    fnTitle = stDirPic + '/' + FNTITLE
    surTitle = pygame.image.load(fnTitle)
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
    DIS.blit(surSysStatus,pos)


def ShowTime(color,pos):
    stNow = GetStrTime()
#    print(type(stNow),stNow)
    stFont = pygame.font.get_default_font()
    objFont = pygame.font.SysFont(stFont,32,False)
#    print(objFont.size(stNow))
    surTime = objFont.render(stNow,True,color)
    DIS.blit(surTime,pos)


def ShowRPM(stDirPic,pos):
    fnRPM = stDirPic + '/' + FNRPM
    surRPM = pygame.image.load(fnRPM)
    DIS.blit(surRPM,pos)

    rpm = random.randrange(400,3800,100)
    stFont = pygame.font.get_default_font()
    objFont = pygame.font.SysFont(stFont,100,False) 
    surRPM = objFont.render(str(rpm),True,YELLOW)
    pos2 = list(pos)
    pos2[0] += 420
    pos2[1] += 80
    print(pos)
    DIS.blit(surRPM,pos2)


def ShowTEM(stDirPic,pos):
    fnTEM = stDirPic + '/' +FNTEM
    surTEM = pygame.image.load(fnTEM)
    DIS.blit(surTEM,pos)
    


def DisInit():
    pygame.init()
    DIS = pygame.display.set_mode((WINWIDTH,WINHEIGHT),pygame.FULLSCREEN|pygame.HWSURFACE)
    #DIS = pygame.display.set_mode((WINWIDTH,WINHEIGHT))
    pygame.display.set_caption("XDM_I")
    DIS.fill(BGCOLOR)
    return DIS

 
def GetStrTime():
    objNow = datetime.datetime.now()
    stNow = objNow.strftime('%Y-%m-%d %H:%M:%S')
    return stNow


if __name__ == '__main__':
    main()



    
