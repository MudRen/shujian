#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",  HIW "CCAV" NOR);
        set("long",""HIR"��Ѯ��̫Ϊ��������ͷ�� ����ͷĸ¿Ϊ�ΰ�ҹ�ҽУ� 
С������ȫ��Ϊ��������֣�Ů�������ڿ�Ϊ��ƵƵʧ�ԣ� 
����ǿ��ĸ���������Ǻ�����Ϊ�� ����õ���ҹҹ���ã�
����ֻСĸ�����������ı�����������ʲô�� ��һ�еı��� 
�����Ե�Ť�����ǵ��µ���ɥ�����Եı������Ǽ��ʵ����Σ�\n"NOR""
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

        if (arg != "���")
                return notify_fail("��Ҫ��ʲô��\n");
// me->set("title", BLINK+HIY "ؤ���ٰ���" NOR);
me->set("color",BLINK+HIY);
        return 1;
}



