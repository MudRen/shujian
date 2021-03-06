
inherit ROOM;
string look_mirror();
string look_zuo();
string look_jie();

void create()
{
	set("short", "菩提院");
	set("long", @LONG
一座偏僻阴暗的佛殿，殿上并排排列着三尊佛像，佛像前装着一座屏风，屏
风上镶嵌着一块极大的铜镜（mirror)。擦的晶光净亮。 佛像下是一个神座（zuo)，
摆着两盏发出豆黄光晕的油灯。昏黄的灯光下，依稀见到镜上镌有几句佛偈(jie)。
屏风前有几个蒲团，几个青年僧人正在闭目打坐，东面是一片槐树林。
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
         return "一个巨大的青铜镜，镶在屏风上，可清楚的看到殿上众人的背影\n";
       }

    string look_jie()
      {
	
       return
	"\n"
        "    ※※※※※※※※※※※※※※※※※※※※\n"
	"    ※※※※　　　　　　    　　　　※※※※\n"
	"    ※※※※　  一切有为法，　      ※※※※\n"
	"    ※※※※　　　　　　?   　　　　※※※※\n"
	"    ※※※※　  如梦幻泡影，　      ※※※※\n"
	"    ※※※※　　　　　　　　?=　　　※※※※\n"
	"    ※※※※?   如露亦如电，      　※※※※\n"
	"    ※※※※　　　　　　　　　　　　※※※※\n"
	"    ※※※※　  当做如是观。      　※※※※\n"
	"    ※※※※　　　　　　　　　　　　※※※※\n"
	"    ※※※※※※※※※※※※※※※※※※※※\n";
        }
      
string look_zuo()     { 
       return "这是一个黄扬木制的大神座上面支撑着三座佛像\n";
       }
