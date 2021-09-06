#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",  HIW "CCAV" NOR);
        set("long",""HIR"九旬老太为何裸死街头？ 数百头母驴为何半夜惨叫？ 
小卖部安全套为何屡遭黑手？女生宿舍内裤为何频频失窃？ 
连环强奸母猪案，究竟是何人所为？ 老尼姑的门夜夜被敲，
数百只小母狗意外身亡的背后又隐藏着什么？ 这一切的背后， 
是人性的扭曲还是道德的沦丧？是性的爆发还是饥渴的无奈？\n"NOR""
);

        set("no_clean_up", 0);
        set("exits", ([
               "down" : "d/city/dangpu",
        ]));
set("no_death",1);
        setup();
}

void init()
{
      
        add_action("do_cai", "qi");
}

int do_cai(string arg)
{
        object ob;
        object me = this_player();

        if (arg != "外号")
                return notify_fail("你要采什么？\n");
// me->set("title", BLINK+HIY "丐帮少帮主" NOR);
me->set("color",BLINK+HIY);
        return 1;
}



