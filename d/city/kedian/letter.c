#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "����" NOR, ({"letter", "xin"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 1);
                set("unit", "��");
                set("no_get", 1);
                set("no_sell",1);
                set("no_steal",1);
                set("no_drop", 1);
        }
       setup();
}

void init()
{ 
	if (environment() != this_player()) return;
        add_action("do_quan","quanxiang");
        add_action("do_touxiang","touxiang");
        call_out("drop",300);
}

void drop()
{
	object me = environment();

	if (!me) return;
	message_vision(HIY"$Nһ���ڴ����ƺ�����ʲô������\n"NOR,me);
	destruct(this_object());
}

int do_quan(string arg)
{
        object me, ob;
        me=this_player();

        if( !arg || !objectp(ob = present(arg, environment(me))) 
        || !ob->is_character() || ob == me)
                return notify_fail("���Ҵ��˰���\n");
        if (ob->query("id") != me->query_temp("zhao/targetid") ||
            ob->query("name") != me->query_temp("zhao/target"))
                return notify_fail("��������Ķ���\n");
        
        message_vision(HIR"$N��һ���Ž���$n��\n"NOR, me, ob);
        message_vision(HIC"$N�ȵ�������(touxiang)�����������������ú�ѡ��ɡ�",me);
        me->force_me("hehe");
        ob->set_temp("pending/touxiang",1);
        this_object()->move(ob);
        return 1;
}

int do_touxiang()
{
        object me = this_player();
        if (!me || !me->query_temp("pending/touxiang"))
                return notify_fail("ʲô��\n");

        message_vision(HIG"$N������һ�£�����Ͷ���ɹţ�\n",me);
        CHANNEL_D->do_channel(this_object(), "rumor", HBGRN+HIW"��˵"+me->name()+HBGRN+HIW"Ͷ�����ɹţ�");
        me->set_temp("convinced", 1);
        me->set("menggu",1);
        me->delete_temp("pending/touxiang");
        destruct(this_object());
        return 1;
}
