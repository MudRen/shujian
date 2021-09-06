#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR "�齣ͨ����" NOR, ({ "shang ling", "shang", "ling" }));
	set_weight(1);
	if (clonep())
	set("long", "����һ�ź�׽�ߵ��齣ͨ�������һ�����֣�ȫ�����ذ�̯���
������һ��׭ͷС�֣�
stock    ����ƷID�� ���۸�  ����Ʒ����̯λ
unstrock ����ƷID��          ����Ʒ��̯λ�ϳ�����
ע���۸��Իƽ�Ϊ��λ\n" );
	set("unit", "��");
	set("value", 5);
	set("material", "paper");
	set("no_sell", "����ͷ����ѳԷ��ļһ�Ҳ������Ǯ��");
	setup();
}

void init()
{
       add_action("do_stock", "stock");
       add_action("do_unstock", "unstock");
}

int do_stock(string arg)
{
        object me,goods;
        int amount, value;
        mapping all_goods;

        me = this_player();

        if (! me->query("is_vendor"))
                return notify_fail("ֻ�д�����ҵ���˲��ܰ�̯��\n");

        if (! present("shang ling", me))
                return notify_fail("����齣ͨ��������ϣ���������ң�С��Ϊ�\n");

        if (! me->query_temp("on_baitan"))
                return notify_fail("��������Ȱڸ�̯λ(baitan)���ܶ��ۻ��\n");

        if (! arg)
                return notify_fail("ָ���ʽ��stock <����> <���ٻƽ�>\n");
	
	if(sscanf(arg,"%s %d",arg,amount) !=2 )
		return notify_fail("ָ���ʽ��stock <����> <���ٻƽ�>\n");
	
	
//        i = sizeof(args = explode(arg, " "));
//
//        i--;
//        if (! sscanf(args[i], "%d", amount)) 
//                amount = 0;
//        else
//                arg = replace_string(arg, " " + amount, "");

        if (! (goods = present(arg, me)) || ! objectp(goods))
                return notify_fail("�����ϲ�û��������\n");

        if (goods->is_character())
                return notify_fail("�㲻�ܷ������\n");

        if (goods->query("money_id"))
                return notify_fail("������ǮҲ�������ۣ�\n");

        if (goods->query("id") == "shang ling")
                return notify_fail("���ⶫ�����ˣ��㿿ʲô���Է���\n");

        if (goods->is_item_make())
                return notify_fail("�ⶫ���Ƕ������ģ�����û��Ըȥ��\n");

        if (sizeof(me->query_temp("vendor_goods")) >= 10)
                return notify_fail("��һ��ֻ�ܰ�ʮ�ֻ���ѱ�����յ������ɡ�\n");

        if (amount > 1000)
                return notify_fail("��Ʒ���ۼ۸���ඨΪһǧ���ƽ�\n");
        
        if (amount < 0)
                return notify_fail("��Ʒ���ۼ۸���С��һ���ƽ�\n");

        value = 10000;

//        if (! value)
//                value = goods->query("value");

        if (amount)
        { 
                value = amount * value;
        }

//        if (! value)
//                return notify_fail("�ⶫ����ֵǮ��û�˻�ȥ��ġ�\n");

        all_goods = me->query_temp("vendor_goods");

        if (! all_goods)
                all_goods = ([ ]);

        all_goods[base_name(goods)] = value;
        me->set_temp("vendor_goods", all_goods);
        message_vision("$N��"+ goods->name(1) + NOR"��Ϊ" +
                       MONEY_D->price_str(value) + NOR"�ļ۸����̯�ӿ�ʼ���ۡ�\n" NOR, me);
        return 1;
}

int do_unstock(string arg)
{
        object me, goods;
        int i, have_it = 0;
        mapping all_goods;
        string *goods_key;
        
        me = this_player();

        if (! me->query("is_vendor"))
                return notify_fail("ֻ�д�����ҵ���˲��ܰ�̯��\n");

        if (! me->query_temp("on_baitan"))
                return notify_fail("��Ŀǰ��û�а�̯��\n");

        if (! arg)
                return notify_fail("unstock <����>\n");

        if (! (goods = present(arg, me)))
                return notify_fail("�㲢û�ж���������\n");

        all_goods = me->query_temp("vendor_goods");

        if (! all_goods)
                return notify_fail("�����ڲ�û�ж����κλ��\n");

        goods_key = keys(all_goods);

        for (i = 0; i < sizeof(goods_key); i++)
        {
                if (base_name(goods) == goods_key[i])
                        have_it = 1;
        }

        if (have_it) 
        {
                map_delete(all_goods, base_name(goods));
                message_vision(CYN"$N��" + goods->name(1) +CYN+
                               "��̯�����������ˡ�\n"NOR, me);
        } else
                return notify_fail("�㲢û�ж���������\n");

        me->set_temp("vendor_goods", all_goods);
        return 1;
}

int query_autoload()
{
        return 1;
} 
