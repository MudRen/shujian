#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "fu");
}

void create()
{
        set_name("������", ({"puti zi", "zi"}));
                set("unit", "��");
                set("long", "����һ�ž�Ө����������ӣ�������ɽ������ǰ����ϡ�ޱȣ�
������������֮ʵ�����ܻ��ٽ٣���ǧ�֣������ͬ�١�\n");
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
                me->add("max_neili", 20);
                me->add("neili", 20);
                message_vision(HIY "$N����һ�������ӣ���Ȼ��ֻ��һ�ɺƵ��ޱȵ�����ֱ�嶥��...\n" NOR, this_player());
        destruct(this_object());
        return 1;
}
