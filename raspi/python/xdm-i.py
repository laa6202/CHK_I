#!/usr/bin/python3

import datetime
import pygame,sys
from pygame.locals import *

FPS = 30
WINWIDTH=720
WINHEIGHT=480
FNLOGO = 'logo.png'
FNTITLE = 'Title.png'


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
    GetStrTime()
    ShowLogo(stDirPic,(0,0))
    ShowTitle(stDirPic,(100,0))
    pygame.draw.line(DIS,NAVYBLUE,(10,110),(710,110),3)

    while True:
        for event in pygame.event.get():
            if event.type == QUIT or (event.type == KEYUP and event.key == K_ESCAPE):
                pygame.quit()
                sys.exit()

        pygame.display.update()
        FPSCLOCK.tick(FPS)

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
    

def DisInit():
    pygame.init()
    DIS = pygame.display.set_mode((WINWIDTH,WINHEIGHT))
    pygame.display.set_caption("XDM_I")
    DIS.fill(BGCOLOR)
    return DIS

 
def GetStrTime():
    objNow = datetime.datetime.now()
    stNow = objNow.strftime('%Y-%m-%d %H:%M:%S')
    print(type(stNow),stNow)
    return stNow


if __name__ == '__main__':
    main()



    
