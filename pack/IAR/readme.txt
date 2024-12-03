install XTX pack in IAR

1.import pack to IAR
     a.  Project->CMSIS-Pack-manager  open pack manager
     b.  CMSIS->Manager->Import Existing Pack to import CMSIS pack XTX.XT32H0.x.x.x.pack


2. copy flashloader folder XTX in /flashloader_output to $Tool /arm/config/flashloader/

  copy 
          XTX\FlashXT32H0xx.board
          XTX\FlashXT32H0xx.flash
          XTX\FlashXT32H0xx.mac
          XTX\FlashXT32H0xx_Ram18KB.out

to D:\Program Files\IAR Systems\Embedded Workbench 9.2\arm\config\flashloader\