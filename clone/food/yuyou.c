// yuyou.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"yu you", "yuyou","you"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ʵ����ͣ���ɫ����͸����ȡ�����ں���ˮ��������������ϡ�\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 1);
		set("food_supply", 60);
	}
}
void init()
  {
        add_action("do_eat", "eat");
        add_action("do_chi", "chi");
  }

int do_eat(string arg)
  {
        object me = this_player();
        object ob = this_object();
        if( !arg || arg != "yu you" || arg == "")
             return notify_fail("��Ҫ��ʲô��\n");
        if( arg == "yuyou" || "yu you" || "you") 
    {
        message_vision(
        "$Nֻ�������ͻ����ޱȣ�����һ�¾�������ȥ��\n$N�������죬ֻ����һ˿ů��Ӹ�������������\n",this_player());
        me->add("neili", 100);
        destruct(ob);
        return 1;
      }
  }
int do_chi(string arg)
  {
        object me = this_player();
        object ob = this_object();
        if( !arg || arg != "yu you" ||  arg == "")
             return notify_fail("��Ҫ��ʲô��\n");
        if( arg == "yuyou" || "yu you" || "you") 
    {
        message_vision(
        "$Nֻ�������ͻ����ޱȣ�����һ�¾�������ȥ��\n$N�������죬ֻ����һ˿ů��Ӹ�������������\n",this_player());
        me->add("neili", 100);
        destruct(ob);
        return 1;
      }
  }