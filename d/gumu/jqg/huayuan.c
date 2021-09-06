//huayuan.c ��԰
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIM"��԰"NOR);
        set("long",@LONG
�����ǻ�԰���������黨��(hua������������һ��С������������ֵ���£�
�����ںɻ��������˻��䣬��ֻ����ſ�ں�Ҷ�ϡ����ɡ��ؽи���ͣ�����Ϸ�
һ����ɽ��������һ�����ȡ�
LONG
    );
        set("item_desc",([
           "hua": "��֦Ҷ������С�̣��黨�������ɫ�����ޱȣ��յ����̲�סȥժ������\n",
           "hill": "����һ����ɽ��һ���ʯ����ɽǰ������ȥ����ʯ�ƺ���Щ��֣�\n"+
                   "��ʯ�����ƺ���Щ��ͬѰ�����������µ������ڼ�ɽǰ��\n",
        ]));

        set("outdoors","�����");
        set("exits",([
              "south": __DIR__"lang1",
        ]));  

        set("objects",([
                 __DIR__"npc/dizi1" : 2,
        ]));

        setup();
}

void init()
{
        add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{    
        object ob, *inv, me = this_player();
        int i;
        
        me = this_player();
        inv = deep_inventory(me);
        i = sizeof(inv);

        if (!arg || (arg != "hua"))
              return notify_fail("��Ҫժʲô����\n");

        if (me->is_busy() || me->is_fighting())
	      return notify_fail("����æ���ģ�\n");

        if (present("qing hua", this_player()))
	      return notify_fail("�����ϲ�����ô������Ҫ��̫̰���ˡ�\n");

        while (i--)
        if( inv[i]->query("drug"))
              return notify_fail("�����ȥժ������Ȼ����֦��С�̣�������ԥ�ط���������\n");

        ob = new(MEDICINE_D("neili/flower"));
        message_vision(HIY"$N�ܿ�֦�ϼ�̣�����ȥժ"HIM"�黨"HIY"����������С�ġ�\n"NOR, this_player());

        ob->set("owner", me->query("id"));
        ob->move(me);

        me->add_busy(random(2));

        if(random(me->query("kar")) < 10 ){
		message_vision(HIY"��֪���䱳��������С�̣���$N����ָ�������ˡ�\n"NOR, this_player());
		me->apply_condition("qinghua_poison", me->query_condition("qinghua_poison")+100);
		log_file("quest/neili",sprintf("%-18s�õ�%s�����黨����\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
		return 1;
        }
	else {
		log_file("quest/neili",sprintf("%-18s�õ�%s��û�����黨����\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",ob->name()), me);
		message_vision(HIY"$N�ƿ����䱳���С�̣����ֽ�"HIM"�黨"HIY"ժ��������\n"NOR, this_player());
		return 1;
	}
}
