//  ma.c   

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "qi");
        add_action("do_ride", "ride");
}

void create()
{
        set_name("������", ({"lingna ma", "ma", "horse" }));
        set_weight(35000);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƥ");
                set("long", "һƥ��׳���������㲻�����￴��\n");
                set("value", 1000);
        }
}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query_temp("marks/��") ) {
                       write("���Ѿ����������ˡ�\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "��������\n",
                        environment(me), ({me}) );
               write("���������ͷ����������������\n");
                this_player()->set_temp("marks/��", 1);
        return 1;
        }
}
