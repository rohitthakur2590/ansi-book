junos-config
system {
    login {
        user rohit {
            uid 2001;
            class super-user;
            authentication {
                ssh-rsa "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQDAepalCOZX+6vXIdUeFasvuYP/HxzsNl36mlEG8i6lzqLjpLG2QHFZ+HuisxWBNCj2AiQ28bro1NR9qu5DSAf9P/Ebs6bcmSVHlTyXtjFYMGAC5sBe7qyIZUj+8LiolzUVGNCk41VHJe0b/JblyeLxLspEnkFryORlicYzM0YSSpd/2v3aG92tSPdaI7/Wb+ZrbDM2dv6sAYnftC/z/C1aSpXUetW77Vc40vxUCYxPWPVn6S4UFNnv5IZHN1RmaLzKJbTjOd2u4KNALSo8pz7BTHp3WMrrU/CovAwbmbhBdbGf7OqM2OV3b861Nl7x7kGTDUVJCDc/LOv571CgUveb/fNUC/x5V4u13EooBpRE5eEV9G+k2QUkD41WcD1gt+njvFvbpvbf2D8yAs3yC1F23K+aMmOyWInlFrsDJkk42INHnKyrc+vmWqVEKUhVDX6O7yNny9twZWpAhBX2A4BLLF1yxE4be0JfDL/ocIzTPHeW6yVaCl7P3KP5Zqp0nck= rothakur@localhost.localdomain";
            }
        }
        user daniel {
            uid 2002;
            class super-user;
            authentication {
                ssh-rsa "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCvLBCvbloQQwbvlrAEU/txha1cvX0lQ1eGCNddiXfE8u/a+C9IVCs8YxyOV5r2MTC+8GLbMMF4XYgizl1Xtsm0VW4YBtJ1jXo36W+eZZJ8GCwWdjYcyjqFyfHBDA1qLR/G09u45wFDf+ohvUMCwPsCk87T5MuwLLkhD3hFpizkpou2rsop3KOd6d8GBUVQ1z29aOIqE1yrsCKqqD2i8f1eA3uhu0r9Rx22YZWnjx7nZ4PVKZrzH1i6KwPw4aO6Ximd7y9dDXnFVSogpN1gwtL1XgqRfmBH9RiGRWtON/vuvXtw4JoWpy8R6t9tXmNM/SjFkwdNMSaHMGgxtKp+YTXF";
            }
        }
    }
    root-authentication {
        encrypted-password "$6$5VKsclfVe/bGhS9s$0g9c0wHm3ssq6LJdsvlL3rYC9QiBmWPaJ1K.6OQ1yk5ZqrI58UBIPE.tQxJIFP8LzgDV3kFSt/D3v70X0fIv/1"; ## SECRET-DATA
        ssh-rsa "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCvLBCvbloQQwbvlrAEU/txha1cvX0lQ1eGCNddiXfE8u/a+C9IVCs8YxyOV5r2MTC+8GLbMMF4XYgizl1Xtsm0VW4YBtJ1jXo36W+eZZJ8GCwWdjYcyjqFyfHBDA1qLR/G09u45wFDf+ohvUMCwPsCk87T5MuwLLkhD3hFpizkpou2rsop3KOd6d8GBUVQ1z29aOIqE1yrsCKqqD2i8f1eA3uhu0r9Rx22YZWnjx7nZ4PVKZrzH1i6KwPw4aO6Ximd7y9dDXnFVSogpN1gwtL1XgqRfmBH9RiGRWtON/vuvXtw4JoWpy8R6t9tXmNM/SjFkwdNMSaHMGgxtKp+YTXF";
    }
    services {
        ssh {
            root-login deny-password;
            no-passwords;
        }
        netconf {
            ssh;
        }
    }
    host-name vsrx;
    syslog {
        file messages {
            any any;
        }
    }
    license {
        autoupdate {
            url https://ae1.juniper.net/junos/key_retrieval;
        }
    }
}
interfaces {
    fxp0 {
        unit 0 {
            family inet {
                dhcp;
            }
        }
    }
}
