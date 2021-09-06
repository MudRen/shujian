// npc: /d/city/npc/wei.c
// Jay 5/15/96
// Modify by Linux@sj Ôö¼Óask Î¤Ğ¡±¦µØÖ·

#include <get_place.h>
inherit NPC;
string ask_beauty();
string ask_me();
void create()
{
        set_name("Î¤´º·¼", ({ "wei chunfang", "chunfang", "wei" }) );
        set("gender", "Å®ĞÔ" );
	set("title", "Àö´ºÔºÀÏ°åÄï");
        set("age", 42);
        set("long", 
            "Î¤´º·¼ÊÇµ±³¯Â¹¶¦¹«¼æºì»¨»á×Ü¶æÖ÷Î¤Ğ¡±¦ËûÄï£¬ËäÊÇĞì"
	    "Äï°ëÀÏ£¬µ«·çÔÏÓÈ´æ¡£\n");
        set("str", 65);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
	set("per", 18);
        set("shen_type", 1);
        set("no_get","Î¤´º·¼¶ÔÄã¶øÑÔÌ«ÖØÁË¡£\n");

	set_skill("force", 20);

        set("combat_exp", 200);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "ÀÏÄïÎÒ¾ÍÊÇÎ¤´º·¼¡£",
            //"Î¤Ğ¡±¦" : "ÄÇÊÇÎÒµÄ¹Ô¶ù×Ó, Ò»Ë«ÑÛ¾¦³¤µÃÏñÄÇ¸öÀ®Âï, ±Ç×ÓÓĞµã¶ùÏñÄÇ¸ö»Ø×Ó¡£",
            "Î¤Ğ¡±¦" : (: ask_me :),
            "wei xiaobao" : (: ask_me :),
            "Àö´ºÔº" : "ÎÒÃÇÀö´ºÔº¿ÉÊÇÑïÖİ³ÇÀïÍ·Ò»·İµÄÕÒÀÖ×ÓÈ¥´¦¡£",
            "here" : "ÎÒÃÇÀö´ºÔº¿ÉÊÇÑïÖİ³ÇÀïÍ·Ò»·İµÄÕÒÀÖ×ÓÈ¥´¦¡£",
            "beauty" : (: ask_beauty :),
       	]) );

        setup();
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "Î¤´º·¼µÃÒâµØËµµÀ£ºµ±ÄêÀÏÄïÎÒ±êÖÂµÃºÜ£¬Ã¿ÌìÓĞºÃ¼¸¸ö¿ÍÈË¡£\n",
                "Î¤´º·¼Å­ÂîµÀ£ºÀ±¿éÂèÂè£¬ÒªÊÇÂŞÉ²¹í¡¢ºìÃ«¹í×Óµ½Àö´ºÔºÀ´£¬ÀÏÄïÓÃ´óÉ¨ÖãÅÄÁË³öÈ¥¡¡£\n",
                "Î¤´º·¼¶ÔÄãËµµÀ£ºÄãÒ»Ë«ÑÛ¾¦Ôôß¯ÎûÎûµÄ£¬ÕæÏñÄÇ¸öÀ®Âï£¡\n",
        }) );
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
string ask_me()
{
       object ob, where;
       object me = this_player();
       ob = find_living("wei xiaobao");
       if (!ob) return "Õâ¸öĞ¡ÍÃáÌ×Ó£¬ÀÏÄïÎÒÒ²²»ÖªµÀËûÈ¥ÄÄÀïÁË¡£\n";
       where = environment(ob);
       if (!where) return "Õâ¸öĞ¡ÍÃáÌ×ÓºÃÏñÏûÊ§ÁËÒ®...\n";  
       if (objectp(present("wei xiaobao", environment(me)))){
          	command("disapp "+me->query("id"));
          	return "ÎÒ¶ù×Ó¾ÍÔÚÕâÀïÑ½...\n";   
       }
       command("look "+me->query("id"));
       return "ÕâÎ»" + RANK_D->query_respect(me) + "£¬²»Â÷ÄúËµ£¬ÎÒÄÇ¹Ô¶ù×ÓÕıÔÚ" + get_place(base_name(where)) + (string)where->query("short") +"Âô±øÆ÷ÄØ¡£";
}
void greeting(object me)
{
	if (!me)
		return;
    	command("look " + me->query("id"));

    	if (me->query("gender")=="ÎŞĞÔ") {
       	command("say Äãµ±ÀÏÄïÊÇÀÃæ»×ÓÂğ£¿À±¿éÂèÂè£¬ÀÏÄïÂúººÃÉ²Ø»Ø¶¼½Ó£¬¾ÍÊÇ²»ËÅºòÌ«¼à£¡");
       	command("kick " + me->query("id"));
       	message("vision", me->name() +"±»Î¤´º·¼Ò»½ÅÌß³öÃÅÍâ¡£\n",
                environment(me), ({me}));
       	me->move("/d/city/nandajie2");
       	message("vision", me->name() +"±»ÈË´ÓÀö´ºÔºÀïÌßÁË³öÀ´£¬ÔÔµ¹ÔÚµØÉÏ£¬¿ÄµôÁ½¿ÅÃÅÑÀ¡£\n", 
                environment(me), ({me}));

    	}
    	else {
    		if (me->query("class") =="bonze") {
       		command("say ßÏ£¬" + RANK_D->query_respect(me) 
			+"Ò²À´¹â¹ËÎÒÃÇÀö´ºÔº°¡¡£");
       		command("say Ïëµ±ÄêÎÒ½Ó¹ıÒ»¸öÎ÷²ØÀ®Âï£¬ËûÉÏ´²Ç°Ò»¶¨ÒªÄî¾­£¬Ò»ÃæÄî¾­£¬ÑÛÖé×Ó¾Í¹ÇÁïÁïµØÇÆ×ÅÎÒ¡£");
		}
    		if (me->query("gender")=="Å®ĞÔ") {
       		command("say °¥Ñ½£¬ÕâÄêÔÂ´ó¹ÃÄïÒ²¹äÒ¤×Ó£¬³ÉºÎÌåÍ³¡£");
       		command("sigh");
       		command("say ¿ÉÏ§ÎÒ¶ù×Ó²»ÔÚ£¬²»È»ÈÃËûËÅºòÄã¡£");
    		}
    	command("say Â¥ÉÏÂ¥ÏÂµÄ¹ÃÄïÃÇ£¬¿ÍÈËÀ´ÁË£¡");
    	}
    	return ;
}

string ask_beauty()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, per = 0;

//	ob_list = sort_array(users(), (: env_cmp :));
	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("per") > per 
		&& ob_list[i]->query("gender") == "Å®ĞÔ"
		&& !ob_list[i]->query("hooker")
		&& where
		&& strsrch(file_name(where), "/d/") >= 0) {
			obj = ob_list[i];
			per = obj->query("per");
		}
	}

	if ( !obj ) {
	msg ="ÌìÄÄ£¬ÏÖÔÚ¾ÓÈ»Ò»¸ö¹ÃÄï¼Ò¶¼Ã»ÓĞ£¬¿Ï¶¨¶¼±»ÄãÃÇÕâ°ï³ôÁ÷Ã¥ÏÅÅÜÁË£¡\n";
	return msg;
	}

	name = obj->query("name")+"("+obj->query("id")+")";
	switch( per/5 )
	{
	case 0:
	case 1:
	case 2:
		msg ="ÏÖÔÚÊé½£Àï¾ÓÈ»Êı"+name+"ÕâÑùÈı·ÖÏóÈË£¬Æß·ÖÏó¹íµÄÄ¸Ò¹²æ×îÆ¯ÁÁ£¬Õâ»¹ÓĞÌìÀíÂğ£¿\n";
		break;
	case 3:
		msg =name+"µÄÏàÃ²»¹²»µ½ÖĞÈËÖ®×Ê£¬ÔõÃ´¾ÍÅÅÉÏËıÁËÄØ£¬´ó¸ÅÊÇÉ½ÖĞÎŞÀÏ»¢£¬ºï×Ó³Æ°ÔÍõ°É£¡\n";
		break;
	case 4:
		msg =name+"µÄÏàÃ²²»²î£¬Äà°ÍÀïÏÖÔÚ¾ÍÊıËıÁË£¬¸Ï¿ì°ïËıÕÒ¸öÀÏ¹«¼ŞÁË°É£¡\n";
		break;
	case 5:
		msg =name+"³¤µÃÄÇ¸öÃÀ°¡£¬Èç¹ûµ½ÎÒÃÇÀö´ºÔºÀ´½Ó¿Í£¬¹Ô¹ÔÁúµÄ¶«¾Â²Ë³´´ó´Ğ£¬±£¹Ü¿ÍÈËÌ¤ÆÆÃÅ¿²×Ó£¡\n";
		break;
	case 6 :
		msg =name+"±ğ²»ÊÇÏÉÅ®ÏÂ·²°É£¬Èç¹ûµ½ÔÛÕâÔº×Ó£¬¿ÖÅÂÁ¬ÉñÏÉÒ²ÊÇÕâÀïµÄ³£¿ÍÄØ£¡\n";
		break;
	}

	return msg;
}
