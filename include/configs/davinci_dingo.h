/*
 * Copyright (C) 2009 Texas Instruments Incorporated
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* Bticino Dingo board */
#define DAVINCI_DINGO

#define CONFIG_WATCHDOG
#define CONFIG_SYS_WATCHDOG_VALUE (5 * 60)

#define CONFIG_SKIP_LOWLEVEL_INIT	/* U-Boot is a 3rd stage loader */
#define CONFIG_SYS_NO_FLASH		/* that is, no *NOR* flash */

#undef CONFIG_ETHADDR			/* For parallel production environment
					 * a fixed MAC address is not good */
#define CONFIG_RANDOM_DM365_ENETADDR	/* A Random MAC address is what we
					 * want, with the first three bytes
					 * configurable.
					 */
#define CONFIG_RANDOM_DM365_ENETADDR_ADDR1	0x00
#define CONFIG_RANDOM_DM365_ENETADDR_ADDR2	0x03
#define CONFIG_RANDOM_DM365_ENETADDR_ADDR3	0x50

#define CONFIG_OVERWRITE_ETHADDR_ONCE

#define CONFIG_SYS_TEXT_BASE		0x81080000

#define CONFIG_SYS_CONSOLE_INFO_QUIET
#define CONFIG_SILENT_CONSOLE
#define CONFIG_SYS_DEVICE_NULLDEV
/* #define CONFIG_DISABLE_CONSOLE */
/* #define CONFIG_DISABLE_PRINTK */
#undef CONFIG_DISPLAY_CPUINFO
#undef CONFIG_DISPLAY_BOARDINFO

#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH

#define CONFIG_MII
#define CONFIG_CMD_MII

/* SoC Configuration */
#define CONFIG_ARM926EJS				/* arm926ejs CPU */
#define CONFIG_SYS_TIMERBASE		DAVINCI_TIMER0_BASE /* use timer 0 */
#define CONFIG_SYS_HZ_CLOCK		24000000	/* timer0 freq */
#define CONFIG_SYS_HZ			1000
#define CONFIG_SOC_DM365
#define CONFIG_CMD_CACHE

/* Memory Info */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM_1			0x80000000
#define PHYS_SDRAM_1_SIZE		(128 << 20)	/* 128 MiB */
#define CONFIG_MAX_RAM_BANK_SIZE	(256 << 20)	/* Max supported */
#define DDR_4BANKS

/* Serial Driver info: UART0 for console  */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	-4
#define CONFIG_SYS_NS16550_COM1		0x01c20000
#define CONFIG_SYS_NS16550_CLK		CONFIG_SYS_HZ_CLOCK
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200

/* EEPROM definitions for EEPROM on DM365 EVM */
#if 0
#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN		2
#define CONFIG_SYS_I2C_EEPROM_ADDR		0x50
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS	6
#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	20
#endif

/* Network Configuration */
#define CONFIG_DRIVER_TI_EMAC
#define CONFIG_EMAC_MDIO_PHY_NUM	0
#define CONFIG_MII
/*
#define CONFIG_BOOTP_DEFAULT
#define CONFIG_BOOTP_DNS
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
*/
#define CONFIG_NET_RETRY_COUNT	10
#define CONFIG_NET_MULTI

/* I2C */
#if 0
#define CONFIG_HARD_I2C
#define CONFIG_DRIVER_DAVINCI_I2C
#define CONFIG_SYS_I2C_SPEED		400000
#define CONFIG_SYS_I2C_SLAVE		0x10	/* SMBus host address */
#endif

/* SD/MMC */
#undef CONFIG_MMC
#if 0
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_DAVINCI_MMC
#define CONFIG_MMC_MBLOCK
#define CONFIG_SYS_MMC_ENV_DEV		0
#endif
#define CONFIG_NAND_DAVINCI
#define CONFIG_SYS_NAND_CS              2
#define CONFIG_SYS_NAND_USE_FLASH_BBT
#define CONFIG_SYS_NAND_4BIT_HW_ECC_OOBFIRST
#define CONFIG_SYS_NAND_PAGE_2K

#define CONFIG_SYS_NAND_LARGEPAGE
#define CONFIG_SYS_NAND_BASE_LIST       { 0x02000000, }
/* socket has two chipselects, nCE0 gated by address BIT(14) */
#define CONFIG_SYS_MAX_NAND_DEVICE      1
#define CONFIG_SYS_NAND_MAX_CHIPS       1

#define PINMUX4_USBDRVBUS_BITCLEAR       0x3000
#define PINMUX4_USBDRVBUS_BITSET         0x2000

/* USB Configuration */
#undef CONFIG_USB_DAVINCI
#undef CONFIG_MUSB_UDC
#undef CONFIG_MUSB_HCD

#ifdef CONFIG_USB_DAVINCI
#define CONFIG_CMD_USB         /* include support for usb      */
#define CONFIG_CMD_STORAGE     /* include support for usb      */
#define CONFIG_CMD_FAT         /* include support for FAT/storage*/
#define CONFIG_DOS_PARTITION   /* include support for FAT/storage*/
#endif

#ifdef CONFIG_MUSB_HCD         /* include support for usb host */
#define CONFIG_CMD_USB         /* include support for usb cmd */
#define CONFIG_USB_STORAGE     /* MSC class support */
#define CONFIG_CMD_STORAGE     /* inclue support for usb-storage cmd */
#define CONFIG_CMD_FAT         /* inclue support for FAT/storage */
#define CONFIG_DOS_PARTITION   /* inclue support for FAT/storage */

#ifdef CONFIG_USB_KEYBOARD     /* HID class support */
#define CONFIG_SYS_USB_EVENT_POLL

#define CONFIG_PREBOOT "usb start"
#endif /* CONFIG_USB_KEYBOARD */
#endif /* CONFIG_MUSB_HCD */

#ifdef CONFIG_MUSB_UDC
#define CONFIG_USB_DEVICE              1
#define CONFIG_USB_TTY                 1
#define CONFIG_SYS_CONSOLE_IS_IN_ENV   1
#define CONFIG_USBD_VENDORID           0x1DA4
#define CONFIG_USBD_PRODUCTID          0x1C
#define CONFIG_USBD_MANUFACTURER       "BTicino S.p.A."
#define CONFIG_USBD_PRODUCT_NAME       "Dingo"
#endif /* CONFIG_MUSB_UDC */

/* U-Boot command configuration */
#include <config_cmd_default.h>

/*
#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_I2C
#define CONFIG_CMD_PING
#define CONFIG_CMD_SAVES
*/

#ifdef CONFIG_MMC
#define CONFIG_DOS_PARTITION
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_CMD_MMC
#endif

#ifdef CONFIG_NAND_DAVINCI
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_PARTITIONS
#define CONFIG_SYS_NAND_ONFI_DETECTION
#define CONFIG_MTD_DEVICE
#undef CONFIG_MTD_DEBUG
#define CONFIG_MTD_DEBUG_VERBOSE 0
#define CONFIG_CMD_NAND
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#define UBI_DEBUG 0
#define CONFIG_LZO
#define CONFIG_RBTREE
#endif

/*
#define CONFIG_CRC32_VERIFY
#define CONFIG_MX_CYCLIC
*/

/* U-Boot general configuration */
#undef CONFIG_USE_IRQ				/* No IRQ/FIQ in U-Boot */
#define CONFIG_BOOTFILE		"uImage"	/* Boot file name */
#define CONFIG_SYS_PROMPT	"Dingo # "	/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE	1024		/* Console I/O Buffer Size  */
#define CONFIG_SYS_PBSIZE			/* Print buffer size */ \
		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	16		/* max number of command args */
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
/* #define CONFIG_SYS_LONGHELP */

#ifdef CONFIG_NAND_DAVINCI
#define CONFIG_ENV_SIZE		(4 << 10)	/* 4 KiB */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OFFSET	0x180000
#undef CONFIG_ENV_IS_IN_FLASH
#endif

#if defined(CONFIG_MMC) && !defined(CONFIG_ENV_IS_IN_NAND)
#define CONFIG_CMD_ENV
#define CONFIG_ENV_SIZE		(4 << 10)	/* 4 KiB */
#define CONFIG_ENV_OFFSET	(0x60000 - CONFIG_ENV_SIZE)	/* Sector 51 */
#define CONFIG_ENV_IS_IN_MMC
#undef CONFIG_ENV_IS_IN_FLASH
#endif

#define CONFIG_BOOTDELAY	1
#define CONFIG_BOOTCOMMAND	"dcache on; icache on; ubi part kernel 2048; ubifsmount kernel; ubifsload 80700000 uImage; bootm"
#define CONFIG_BOOTARGS \
		"console=ttyS0,115200n8 " \
		"ubi.mtd=5,2048 root=ubi0:dingo-rootfs rootfstype=ubifs " \
		"video=davincifb:osd0=320x240x16,2025K@0,0:osd1=320x240,2025K@0,0:vid0=off:vid1=off " \
		"davinci_enc_mngr.ch0_mode=NON-STANDARD davinci_enc_mngr.ch0_output=LCD quiet lpj=671744"
/*
#define CONFIG_CMDLINE_EDITING
#define CONFIG_VERSION_VARIABLE
#define CONFIG_TIMESTAMP
*/

/* U-Boot memory configuration */
#define CONFIG_STACKSIZE               (256 << 10)     /* 256 KiB */
#define CONFIG_SYS_MALLOC_LEN          (1 << 20)       /* 1 MiB */
#define CONFIG_SYS_MEMTEST_START       0x87000000      /* physical address */
#define CONFIG_SYS_MEMTEST_END         0x88000000      /* test 16MB RAM */

/* Linux interfacing */
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_SYS_BARGSIZE    1024                    /* bootarg Size */
#define CONFIG_SYS_LOAD_ADDR   0x80700000              /* kernel address */

/* NAND configuration issocketed with two chipselects just like the DM355 EVM.
 * It normally comes with a 2GByte SLC part with 2KB pages
 * (and 128KB erase blocks); other
 * 2GByte parts may have 4KB pages, 256KB erase blocks, and use MLC.  (MLC
 * pretty much demands the 4-bit ECC support.)  You can of course swap in
 * other parts, including small page ones.
 */
#define MTDIDS_DEFAULT		"nand0=davinci_nand.0"

#ifdef CONFIG_SYS_NAND_LARGEPAGE
/*  Use same layout for 128K/256K blocks; allow some bad blocks */
#define PART_BOOT		"1792k(bootloader)ro,"
#else
/* Assume 16K erase blocks; allow a few bad ones. */
#define PART_BOOT		"512k(bootloader)ro,"
#endif

#define PART_KERNEL_R		"8m(kernel_r),"	/* kernel + initramfs */
#define PART_KERNEL_P		"8m(kernel),"	/* kernel + initramfs */
#define PART_REST_R		"20m(fs_r),"
#define PART_REST_P		"70m(fs_p),"
#define PART_EXTRA		"-(extra)"

#define MTDPARTS_DEFAULT	\
	"mtdparts=davinci_nand.0:" PART_BOOT PART_KERNEL_R PART_REST_R PART_KERNEL_P PART_REST_P PART_EXTRA


#define CONFIG_EXTRA_ENV_SETTINGS \
	"mtdparts=" MTDPARTS_DEFAULT "\0" \
	"verify=no" "\0" \
	"silent=yes" "\0"

#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_AUTOBOOT_KEYED
#define CONFIG_AUTOBOOT_STOP_STR                "S"
#define CONFIG_AUTOBOOT_PROMPT			"booting...\n"

/* additions for new relocation code, must added to all boards */
#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x1000 - /* Fix this */ \
					GENERATED_GBL_DATA_SIZE)

#endif /* __CONFIG_H */
