import pygame

wind = (600,100)
display = pygame.display.set_mode(wind)
clock = pygame.time.Clock()



color = [(255,0,0),(0,255,0)]
ind = 0

width = 0
rec = False
buffer = []

co = 0
while True:

    

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            break

        if event.type == pygame.MOUSEMOTION:
            print(buffer)
            width = event.pos[0]

        if event.type == pygame.MOUSEBUTTONDOWN:
            rec = True
            ind = 1
            buffer = []

    if co == 35:
        rec = False
        co = 0
        ind = 0
        print(buffer)


    display.fill((0, 0, 255))        
    pygame.draw.rect(display, color[ind], (0, 0, width, 100))
    
    if rec:
        co += 1
        buffer.append(width)

    pygame.display.flip()
    clock.tick(5)
