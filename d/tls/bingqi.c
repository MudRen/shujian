inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������µı������������µ��书һ�����Կ���Ϊ��������
������Ȼ׼����һЩ�����������ŵĵ���ʹ�á�ǽ�ߵı�����(jia)�Ϸ���
��ʽ�����ı��������Ը����Լ�ϲ�ã�ѡ���ֵġ�
LONG);
        set("exits", ([
           "west" : __DIR__"cby",
        ]));
 set("item_desc", ([ 
"jia" : "�����ܷ��Ÿ�ʽ�����ı�����
һ��ֻ����һ����
        �ֽ�(jian)           ����(armor)        ����(changjian)
        ����(changbian)     ��(zhujian)        �̽�(duanjian)
        ��(zhujian)      

�������(na)һ������������
\n"
]));
	set("coor/x",-330);
  set("coor/y",-280);
   set("coor/z",30);
   setup();

}

void init()
{
	add_action("do_na","na");
}

int do_na(string arg)
{
        mapping fam; 
	object me;
       	me=this_player();
        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "������")
		return notify_fail("�㲻�������µ��ӣ���������ȡ�����ģ���\n");

	if (me->query_temp("marks/��1") )
		return notify_fail("�������˱�������Ҫ���𣿣�\n");

	if (arg=="all from jia") 
		return notify_fail("����ôҪ��ô�����ѽ����ȥ��������\n");

	if (!arg) return notify_fail("��Ҫ��ʲô������\n");

	if (!"jian from jia"||!"changjian from jia"||!"duanjian from jia"
||!"zhujian from jia"||!"changbian from jian"
||!"armor from jia") return 0;

	if (arg=="jian from jia"){
       	message_vision("$N�ӱ��������ó�һ�Ѹֽ���\n",me);
	this_player()->set_temp("marks/��1", 1);
	me = new("/d/city/obj/gangjian");
        me->move(this_player());
	return 1;
	}
	
	if (arg=="changjian from jia"){
       	message_vision("$N�ӱ��������ó�һ�ѳ�����\n",me);
	this_player()->set_temp("marks/��1", 1);
	me = new("/d/city/obj/changjian");
        me->move(this_player());
	return 1;
	}

	if (arg=="duanjian from jia"){
       	message_vision("$N�ӱ��������ó�һ�Ѷ̽���\n",me);
	this_player()->set_temp("marks/��1", 1);
	me = new("/d/city/obj/duanjian");
        me->move(this_player());
	return 1;
	}

	if (arg=="zhujian from jia"){
       	message_vision("$N�ӱ��������ó�һ���񽣡�\n",me);
	this_player()->set_temp("marks/��1", 1);
	me = new("/d/village/obj/zhujian");
        me->move(this_player());
	return 1;
	}
	

	if (arg=="changbian from jia"){
       	message_vision("$N�ӱ��������ó�һ�����ޡ�\n",me);
	this_player()->set_temp("marks/��1", 1);
     me = new("/clone/weapon/changbian");
        me->move(this_player());
	return 1;
	}
	if (arg=="armor from jia"){
       	message_vision("$N�ӱ��������ó�һ�����ס�\n",me);
	this_player()->set_temp("marks/��1", 1);
	me = new("/d/city/obj/tiejia");
        me->move(this_player());
	return 1;
	}
      
        if (arg=="zhubang from jia"){
       	message_vision("$N�ӱ��������ó�һ�������\n",me);
	this_player()->set_temp("marks/��1", 1);
	me = new("/d/city/obj/zhubang");
        me->move(this_player());
	return 1;
	}

        if (arg=="gangzhang from jia"){
       	message_vision("$N�ӱ��������ó�һ�����ȡ�\n",me);
	this_player()->set_temp("marks/��1", 1);
	me = new("/d/city/obj/gangzhang");
        me->move(this_player());
	return 1;
	}
}

