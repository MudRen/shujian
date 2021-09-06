
inherit ROOM;
string look_mirror();
string look_zuo();
string look_jie();

void create()
{
	set("short", "ÆÐÌáÔº");
	set("long", @LONG
Ò»×ùÆ«Æ§Òõ°µµÄ·ðµî£¬µîÉÏ²¢ÅÅÅÅÁÐ×ÅÈý×ð·ðÏñ£¬·ðÏñÇ°×°×ÅÒ»×ùÆÁ·ç£¬ÆÁ
·çÉÏÏâÇ¶×ÅÒ»¿é¼«´óµÄÍ­¾µ£¨mirror)¡£²ÁµÄ¾§¹â¾»ÁÁ¡£ ·ðÏñÏÂÊÇÒ»¸öÉñ×ù£¨zuo)£¬
°Ú×ÅÁ½Õµ·¢³ö¶¹»Æ¹âÔÎµÄÓÍµÆ¡£»è»ÆµÄµÆ¹âÏÂ£¬ÒÀÏ¡¼ûµ½¾µÉÏïÔÓÐ¼¸¾ä·ðÙÊ(jie)¡£
ÆÁ·çÇ°ÓÐ¼¸¸öÆÑÍÅ£¬¼¸¸öÇàÄêÉ®ÈËÕýÔÚ±ÕÄ¿´ò×ø£¬¶«ÃæÊÇÒ»Æ¬»±Ê÷ÁÖ¡£
LONG
	);

	set("exits", ([
	
	    "east" : __DIR__"huaishu1",	
       	]));

	set("item_desc",([
	"mirror" : (: look_mirror :),
        "zuo" :    (: look_zuo :),
        "jie" :    (: look_jie :), 
	]));

	set("objects",([
		CLASS_D("shaolin") + "/xuan-du" : 1,
	]));

	set("coor/x",10);
  set("coor/y",300);
   set("coor/z",120);
   setup();
}


  string look_mirror()
       {
         return "Ò»¸ö¾Þ´óµÄÇàÍ­¾µ£¬ÏâÔÚÆÁ·çÉÏ£¬¿ÉÇå³þµÄ¿´µ½µîÉÏÖÚÈËµÄ±³Ó°\n";
       }

    string look_jie()
      {
	
       return
	"\n"
        "    ¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡¡¡    ¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡  Ò»ÇÐÓÐÎª·¨£¬¡¡      ¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡¡¡¡   ¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡  ÈçÃÎ»ÃÅÝÓ°£¬¡¡      ¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¢=¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡   ÈçÂ¶ÒàÈçµç£¬      ¡¡¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡  µ±×öÈçÊÇ¹Û¡£      ¡¡¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
	"    ¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n";
        }
      
string look_zuo()     { 
       return "ÕâÊÇÒ»¸ö»ÆÑïÄ¾ÖÆµÄ´óÉñ×ùÉÏÃæÖ§³Å×ÅÈý×ù·ðÏñ\n";
       }
