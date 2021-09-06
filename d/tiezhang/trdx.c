// add quest by yanyang 2000/8/25 , about a armor


inherit ROOM;
#include <ansi.h>
string look_bei();
void close_passage();
void create()
{
        set("short", HIR"ÌìÈ»¶´Ñ¨"NOR);
        set("long", @LONG
ÕâÊ¯¶´ÏµÌìÈ»Éú³É£¬½ÏÖ®ÍâÃæÈË¹¤¿ªÔäµÄÊ¯ÊÒ´óÁËÊ®À´±¶¡£·ÅÑÛÍûÈ¥£¬¶´
ÄÚ¹²ÓĞÊ®Óà¾ßº¡¹Ç£¬»ò×ö»òÎÔ£¬ÉñÌ¬¸÷ÓĞ²»Í¬£¬ÓĞµÄº¡¹ÇÉ¢¿ªÔÚµØ£¬ÓĞµÄÈ´ÈÔ
¾ßÍêºÃÈËĞÎ£¬¸üÓĞĞ©¹ÇÌ³ÁéÎ»Ö®Êô¡£Ã¿¾ßº¡¹ÇÖ®ÅÔ¶¼·Å×Å±øÈĞ£¬°µÆ÷£¬ÓÃ¾ß£¬
Õä±¦µÈÎï¡£¶´¿Ú´¦Á¢×ÅÒ»×ùÊ¯±®(bei)¡£
LONG
        );

        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));

        set("item_desc",([
        "bei"         :       (: look_bei :),
        ]));

        set("objects", ([
            __DIR__"obj/haigu" : 1,  
//            __DIR__"obj/ycj" : 1,  by tangfeng
        ]));

        set("no_clean_up", 0);
        setup();

}
string look_bei()
{
        return
        "\n"
"    Ì   ÉÃ¶¯ÊÒÄÚÎïÆ·Õß\n"    
        "\n"
HIR"        ËÀÉËÄª¹Ö£¡    \n"NOR
        "\n";
}

void init()
{
        add_action("do_move", "move");
        add_action("do_find", "find");
}

int do_move(string arg)
{
      object me;
      me=this_player();

      if ((int)me->query_temp("marks/baowu")) 
      {
      if ((int)me->query_str() < 30)
          return notify_fail("ÄãµÄÁ¦Á¿²»¹»£¬ÎŞ·¨½«Ê¯±®ÍÆ¿ª¡£\n");
      if (!arg || arg !="bei") 
          return notify_fail("ÄãÒªÍÆÊ²Ã´£¿£¿\n");
      write("ÄãÔúÏÂÂí²½£¬ÉîÉîµÄÎüÁË¿ÚÆø£¬½«Ê¯±®»º»ºµÄÏòÅÔÍÆ¿ª¡£\n");
      message("vision",me->name() + "Ë«°òÓÃÁ¦£¬Æø³Áµ¤Ìï£¬Ê¯±®»º»ºÏòºóÒÆ¿ª£¬ÏÂÃæÂ¶³öÒ»¸öºÚ¶´¶´µÄÈë¿Ú¡£\n", environment(me),({me}));
      set("exits/enter", __DIR__"taijie-1");
      remove_call_out("close_passage");
      call_out("close_passage", 5);
      return 1;
      }
      return notify_fail("ÕÒËÀ°¡£¡\n");
}

int do_find(string arg)
{
      object me=this_player();
      object kaijia;
      mapping fam = me->query("family");
      
      if(!fam || fam["family_name"] != "ÌúÕÆ°ï" || fam["master_name"] != "ÉÏ¹Ù½£ÄÏ" || !me->query_temp("marks/baowu")){
        write(HIR"ÌúÕÆÖØµØ£¬ÉÃ¶¯ÊÒÄÚÎïÆ·£¬ËÀÉËÄª¹Ö£¡\n"NOR);
        return 1;
        }

      if (!arg || arg != "baowu")
        return notify_fail("ÄãÒªÕÒÊ²Ã´£¿\n");
      if(me->query("jingli")<100) return notify_fail("ÄãÃ»ÓĞ¾«Á¦ÔÙÕÒ¶«Î÷ÁË£¡\n");
      if(me->is_busy()) return notify_fail("ÄãÏÖÔÚĞÄÇé»¹Ã»ÓĞÆ½¾²ÏÂÀ´£¡\n");
      if(random(10)>6) {
        me->start_busy(2);
        return notify_fail(BLU"Í»È»£¬Äã·¢ÏÖÉí±ßµÄÒ»¾ßº¡¹ÇºÃÏñ¶¯ÁËÒ»ÏÂ£¬Äã±»ÏÅ³öÁËÒ»ÉíÀäº¹£¡\n"NOR);
        }
      if(random(10)!=6) {
        me->add("jingli",-100);
        return notify_fail("ÄãĞ¡ĞÄÒíÒíÔÚÒÅº¡ÖĞ×ĞÏ¸µÄÑ°ÕÒ×Å¡£\n"); 
        }
      kaijia = unew(ARMOR_D("yuxue-kaijia"));
      if(!clonep(kaijia)) { 
        write("½á¹û£¬ÕÒÁË°ëÌì£¬ÄãÃ»ÕÒµ½Ò»¼şÏóÑùµÄ¶«Î÷³öÀ´¡£\n");
        return 1;
        }  
      write("ÖÕÓÚ£¬ÄãÔÚÒ»¾ßº¡¹ÇÅÔ·¢ÏÖÒ»¼şÑªºìÉ«µÄîø¼×¡£\n");
      message_vision("$N½«îø¼×Ğ¡ĞÄµÄÄÃÆğ£¬¿«µôÉÏÃæµÄÄàÍÁ¡£\n",me);
      kaijia->move(me);
      return 1;
}

void close_passage()
{
      if( !query("exits/enter") ) return;
      message("vision", "Ê¯±®·¢³öÂ¡Â¡µÄÉùÒô£¬»º»ºÒÆ»ØÔ­´¦¡£\n", this_object() );
      delete("exits/enter");
}
