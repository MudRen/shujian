#include <ansi.h>
inherit F_CLEAN_UP;

int baitan(object me);
int halt_baitan(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object where;

        where = environment(me);

        if (! me->query("is_vendor"))
                return notify_fail("ֻ�д�����ҵ���˲��ܰ�̯��\n");

        if (! present("shang ling", me))
                return notify_fail("�����������ϣ���������ң�С��Ϊ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹�Ǻúô���ļܰɡ�\n");

        if (me->query_temp("on_baitan"))
                return notify_fail("�������Ѿ�ռ��һ��̯λ�������ʿɶ�ֹ�ɡ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ�û�����̯��㡣\n");

        if (me->query_condition("killer"))
                return notify_fail("���ڹٸ������������أ��ѵû��������̯��\n");

        if (where->query("no_trade"))
                return notify_fail("���ﳣ�йٱ���Ѳ�ߣ���û����ط������⡣\n");

        if (where->query("no_fight") && ! where->query("can_trade"))
                return notify_fail("����ط��������ӣ����ǻ����ط�������ɡ�\n");

        message_vision(WHT "$N" WHT "Ѱ�˿�յأ�һƨ�����������������"
                       "��һ�鲼̯���ڵء�\n" NOR, me);
        tell_object(me, HIC "��������԰���(" HIW "stock" HIC ")�������"
                        "����(" HIW "unstock" HIC ")ĳ�ֻ��\n" NOR);

        me->set_temp("on_baitan", 1);
        me->delete("vendor_goods");
        me->set("disable_type"," <��̯��> ");;
	me->start_busy(1);

        return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : baitan

��̯��㣬���ۻ��

HELP);
        return 1;
}
