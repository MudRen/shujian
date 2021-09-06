// Room: /d/tiezhang/mishi.c
//BY BOBO@sj 2000/1/27

inherit ROOM;
#include <ansi.h>
void init();
void create()
{
        set("short", HIY"����"NOR);
        set("long", @LONG
�����ٲ������һ�����ң����³����ѻ������ǳ�ʱ�����˵��������й�
����İ���һ��ʯ��(table)��������һֻ���߼�����ʯ��(he)���п����˷�
�����������ޱ��
LONG
        );

        set("exits", ([ 
        "out" : __DIR__"hhyuan-3",
        ]));

        set("item_desc", ([ 
        "he" : "һ�����ķ�����ʯ�У����������˳�����\n",
        "table" : "����һ�����ʯ��ɵ�ʯ������������˺��Ļҳ���\n",
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        
        object me = this_player();
        
        if((int)me->query_skill("dodge",1) <= 30) 
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$Nֻ���ñ��ٲ������ҡ�һΣ�����վ�ȣ����岻��������ˤ���ٲ�֮�⣡\n"NOR, me);
                me->move(__DIR__"hhyuan-3");
                tell_object(me, HIR"����ٲ���ˤ�˳�����ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
                message("vision", HIR"ֻ��" + me->query("name") + "���ٲ���ˤ�˳��������ڵ��ϰ�������������\n"NOR, environment(me), me);
        }

        add_action("do_open","open");
        add_action("do_study", ({"du", "study",}));
}

int do_open(string arg)
{
        object me = this_player();
        object ob;

       
    if (!arg || (arg != "he" && arg != "shi he"))
       {
        return notify_fail("�����ʲô��\n");
        return 1;
       }
    else
    {
    if (!present("tiezhang zhangpu",me))
       {
        write("��������ʯ�У�����������һ�������������鼮���㼱æ���������ڻ��С�\n");
        ob=new(__DIR__"obj/zhangpu");
        ob->move(me);
        return 1;
       }
        write("��������ʯ�У���������տյ�ʲôҲû�С�\n");
        return 1;
    }
}

int do_study(string arg)
{
        object me;
        int jing_cost;
        me = this_player();

        if ( !arg || ( arg != "table" ) )
                return notify_fail("�����ʲô��\n");

        if ( (int)me->query_skill("guiyuan-tunafa", 1) < 1)
                return notify_fail("���������ʯ���ϵ��ķ�������û�й�Ԫ���ɷ��Ļ��ͣ�������ô��Ҳ�޷���⡣\n");

        jing_cost = (-1) * random(20);
        if((int)me->query("jing") < jing_cost)
                return notify_fail("�����ھ����޷����У�\n");
        if ( (int)me->query_skill("tiezhang-xinfa", 1) > 100)
                return notify_fail("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
        
        me->improve_skill("tiezhang-xinfa", me->query("int"));
        write("�����ʯ����ĥ��һ�ض����ƺ��������ķ��е��ĵá�\n");
        message("vision",me->name() + "��ר���ж�ʯ���ϵ������ķ���\n", environment(me), ({me}));
        me->add("jing", jing_cost);
        return 1;
}


