{
  "targets": [
    {
      "target_name": "oled-exp-addon",
      "sources": [ "oledexpaddon.cc" ],
      "cflags": [
                  "-I /home/rajiv/OpenWRT-Buildroot/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2/usr/include/" ,
                  "-I /home/rajiv/OpenWRT-Buildroot/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/include/"],
      "ldflags": ["-L /home/rajiv/OpenWRT-Buildroot/openwrt/staging_dir/target-mips_34kc_uClibc-0.9.33.2/usr/lib/", 
"-lonionoledexp"]
         

    }
  ]
}
