//  instrument: dongbula.c
// Jay 3/18/96

inherit ITEM;

//void setup()
//{}

void init()
{
        add_action("do_play", "play");
}

void create()
{
        set_name("������", ({"dongbula"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ά�����������������������������(play)����\n");
                set("value", 100);
        }
//        setup();
}

int do_play(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ����ʲô��\n");
        switch( random(3) ) {
                case 0:
                        message_vision("$N���𶬲���������س�����\n"
"����ңԶ�ĵط�����λ�ù��ÿ�������߹�����ձ������Ҫ����\n"
"�����������\n", this_player());
                        break;
                case 1:
                        message_vision("$N���𶬲��������ֵس�����\n"
"����ǵ�ʯͷԲ��Ӳ����ϴ�����ඣ�����ǵĹ�����ӳ����ֻ�۾���Ư����\n", this_player());
                        break;
                case 2:
                        message_vision("$N���𶬲��������˵س�����\n"
"���̲�ϵ�һ����Ȫ����ɽ�ϵ�һ��ѩ�����籩������Զ��ͣ����������ʲôʱ�򰡣�"
"���ܼ������Ц����\n", this_player());
                        break;
        }
        return 1;
}

