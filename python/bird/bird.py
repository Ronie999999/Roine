import pygame
import random
import time

pygame.init()

frame = 0
width = 284
height = 512
FPS = 60
gravity = 2

clock = pygame.time.Clock()
game_screen = pygame.display.set_mode((width, height))
background = pygame.image.load("images/background.png")
bird_up = pygame.image.load("images/bird_wing_up.png")
bird_down = pygame.image.load("images/bird_wing_down.png")
pipe_body = pygame.image.load("images/pipe_body.png")
pipe_end = pygame.image.load("images/pipe_end.png")
pipes = [[200,4]]
bird = [40, height // 2]

def draw_pipes():
    global pipes
    for i in range(len(pipes)):
        for m in range(pipes[i][1]):
            game_screen.blit(pipe_body, (pipes[i][0], m * 32))
        for m in range(pipes[i][1] + 6, 16):
            game_screen.blit(pipe_body, (pipes[i][0], m * 32))
        game_screen.blit(pipe_end, (pipes[i][0], pipes[i][1]*32))
        game_screen.blit(pipe_end, (pipes[i][0], (pipes[i][1]+5)*32))
        pipes[i][0] -= 1
                   

def draw_bird(x, y):
    global frame
    if 0 <= frame < 15 or 30 <= frame < 45:
        game_screen.blit(bird_up, (x, y))
        frame = frame + 1
        
    if 15 <= frame < 30 or 45 <= frame <= 60:
        game_screen.blit(bird_down, (x, y))
        frame = frame + 1
        if frame == 60:
            frame = 1
def safe():
    if bird[1] > height - 35:
        return False
    if bird[1] < 0:
        return False
    if pipes[0][0] - 30 < bird[0] < (pipes[0][0] + 79):
        if bird[1] < (pipes[0][1] + 1)*32 or bird[1] > (pipes[0][1] + 4)*32:
            return False
    return True

def reset():
    global frame, width, height, FPS, gravity, pipes, bird
    frame = 0
    width = 284
    height = 512
    FPS = 60
    gravity = 2
    pipes.clear()
    bird.clear()
    pipes = [[200, 4]]
    bird = [40, height // 2]

def main():
    while True:
        if not safe():
            time.sleep(3)
            reset()
            
        if len(pipes) < 4:
            x = pipes[-1][0] + 200
            open_pos = random.randint(1, 9)
            pipes.append([x, open_pos])
        if pipes[0][0] < -100:
            pipes.pop(0)
            
        
        game_screen.blit(background, (0, 0))
        draw_bird(bird[0], bird[1])
        draw_pipes()
        bird[1] += gravity
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                bird[1] -= 40
                
            if event.type == pygame.QUIT:
                pygame.quit()
                return
        pygame.display.update()
        
            
        clock.tick(FPS)

main()
