// zongzi.c ����

inherit ITEM;
//inherit F_FOOD;

void create()
{
       set_name("����", ({"zong zi","zongzi", "zong"}));
       set_weight(150);
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long", "һ������������ӣ���˵��һ���Ե��˻����1������ֵ��\n");
               set("unit", "��");
               set("value", 100);
               //set("food_remaining", 3);
               //set("food_supply", 30);
       }
}

void init()
{
       add_action("do_drink", ({"eat","chi"}) );
}

int do_drink(string arg)
{
        object me = this_player();
        object ob = this_object();

        if (!arg || !id(arg))
                return 0;	
        message_vision("$N�����ӳԵøɸɾ�����\n",me);
        me->add("food", 500);
	me->add("water",500);
	destruct(ob);
	return 1;
}