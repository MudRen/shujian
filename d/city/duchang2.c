inherit ROOM;

void create()
{
        set("short", "¶Ä³¡");
        set("long", @LONG
        [1;33m¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ[0m
            [1;33m¡Õ¡Õ[0m                                [1;33m¡Õ¡Õ[0m
            [1;33m¡Õ¡Õ[0m ¡¡[1;33;41m¹°[0m    [1;33;41mÖí[0m¡¡¡¡[1;33;41m°ï[0m¡¡¡¡[1;33;41m×Ü[0m   [1;33;41m¶æ[0m  [1;33m  ¡Õ¡Õ[0m
            [1;33m¡Õ¡Õ[0m                                [1;33m¡Õ¡Õ[0m
            [1;33m¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ¡Õ[0m

    ÕâÀïÓÐËÄÌõ×ßÀÈÍ¨Ïò²»Í¬µÄ¹°Öí·¿¼ä¡£·¿¼äÀïÃæµÆ»ðÍ¨Ã÷£¬ÓÀÔ¶×¼±¸
×ÅÎª¹°Öí¿ñÃÇ·þÎñ¡£Ç½ÉÏÌù×ÅÒ»ÕÅ·¢»ÆµÄÖ½(paper)£¬ÉÏÃæÐ´×Å¹°ÖíÃÅµÄ
¼¶±ð¡£Äã¿ÉÒÔ²é¿´¸÷¹°Öí·¿(pigroom)µÄÈËÊý×´¿ö¡£
LONG
        );
        
        set("item_desc", ([
                "paper" : 
"¡¾¹°Öí°ï¡¿µÄ¼¶±ðÓÉµÍµ½¸ß·ÖÎª£º\n\n"
"ÐÂÊÖ£¬Ñ§Í¯£¬Í¯Éú£¬ÊéÉú£¬Ðã²Å£¬\n"
"¾ÙÈË£¬½âÔª£¬¹±Ê¿£¬»áÔª£¬½øÊ¿£¬\n"
"Êü¼ªÊ¿£¬´«ëÍ£¬Ì½»¨£¬°ñÑÛ£¬×´Ôª£¬\n"
"º²ÁÖ£¬Ñ§Ê¿£¬´óÑ§Ê¿£¬Ê×¸¨£¬ÁìÐä£¬\n"
"´ó×ÚÊ¦£¬°ïÖ÷\n"
        ]));
        
        set("exits", ([
        "east" : __DIR__"eproom",
        "west" : __DIR__"wproom",
        "south" : __DIR__"sproom",
        "north" : __DIR__"nproom",
        "down" : __DIR__"duchang",
        ]));

        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("objects", ([
               __DIR__"npc/qian-laoben" : 1,
        ]));

        set("coor/x",90);
  set("coor/y",-20);
   set("coor/z",10);
   set("incity",1);
	setup();
        "/clone/board/pig_b"->foo();
}


void init()
{
    add_action("do_pigroom", "room");
    add_action("do_pigroom", "pigroom");
}

int do_pigroom()
{
	object env1, env2, env3, env4;
    object *obj1, *obj2, *obj3, *obj4;
    object me = this_player();
    int i, i1, i2, i3, i4;

	env1 = load_object(__DIR__"eproom.c");
	obj1 = all_inventory(env1);

	env2 = load_object(__DIR__"nproom.c");
	obj2 = all_inventory(env2);

	env3 = load_object(__DIR__"sproom.c");
	obj3 = all_inventory(env3);

	env4 = load_object(__DIR__"wproom.c");
	obj4 = all_inventory(env4);


    for (i = 0; i < sizeof(obj1); i++) 
        if (userp(obj1[i]))
            i1++;

    for (i = 0; i < sizeof(obj2); i++) 
        if (userp(obj2[i]))
            i2++;

    for (i = 0; i < sizeof(obj3); i++) 
        if (userp(obj3[i]))
            i3++;

    for (i = 0; i < sizeof(obj4); i++) 
        if (userp(obj4[i]))
            i4++;

        tell_object(me, "ÏÖÔÚ¸÷¹°Öí·¿ÀïµÄÈËÊýÓÐ£º\n" + 
        "¡¡¡¡¡¡¡¡±±" + "\n" +
        "¡¡¡¡¡¡¡¡" + i2 + "\n" +
        "¡¡Î÷ " + i4 + "¡¡¡¡¡¡" + i1 + " ¶«\n" + 
        "¡¡¡¡¡¡¡¡" + i3 + "\n" +
        "¡¡¡¡¡¡¡¡ÄÏ \n");
    return 1;
}

