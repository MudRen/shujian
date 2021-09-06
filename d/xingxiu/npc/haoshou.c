// haoshou.c ºÅÊÖ

inherit NPC;

void create()
{
        set_name("ĞÇËŞÅÉºÅÊÖ", ({ "hao shou", "haoshou", "shou" }));
        set("long",
                "ËûÊÇĞÇËŞÅÉµÄ´µ¹ÄÊÖ¡£\n"
                "ËûÊÖÖĞÄÃ×ÅÒ»Ö»Í­ºÅ£¬¹Ä×ãÁ¦Æø³Á×íµØ´µ×Å¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen", -150);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 35);
        set_skill("parry", 30);

        setup();
        set("chat_chance", 2);

        set("chat_msg", ({
		"ºÅÊÖ´µÁË´µÍ­ºÅ£¬¸ßÉù³ªµÀ£¬¡°ĞÇ¡«ËŞ¡«ÀÏ¡«ÏÉ£¬Íş¡«Õğ¡«å¾¡«Óî¡±¡£\n",
		"ºÅÊÖ´µÁË´µÍ­ºÅ£¬¸ßÉù³ªµÀ£¬¡°ĞÇ¡«ËŞ¡«ÀÏ¡«ÏÉ£¬µÂ¡«Åä¡«Ìì¡«µØ¡±¡£\n",
		"ºÅÊÖ´µÁË´µÍ­ºÅ£¬¸ßÉù³ªµÀ£¬¡°ĞÇ¡«ËŞ¡«ÀÏ¡«ÏÉ£¬¹Å¡«½ñ¡«ÎŞ¡«±È¡±¡£\n",
        }) );
        carry_object(BINGQI_D("tonghao"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
