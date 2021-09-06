// Room: /d/shaolin/qyping.c

inherit ROOM;

void create()
{
	set("short", "����ƺ");
	set("long", @LONG
����������Ҿ�������Ŀ��ȥ��ֻ���������ƣ���������룻��ɽ�δ�
���ƽ�����졣ɽ������ٲ���к���£�ʯ���������ۣ�����һ�����棬��
�˷׷����ϣ��������Ρ���ǰ��ƽ���ϴ�ݲ������������þ���Χ��һȦ��
Ȧ�����ƺ���ʲô�������������⡣
LONG);
	set("exits", ([
		"southdown" : __DIR__"shulin14",
		"enter" : __DIR__"fumoquan",
	]));

	set("outdoors", "shaolin");
   	setup();
}
int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}
int valid_leave(object me, string dir)
{
	object *inv = deep_inventory(me);
	object *obj;
	obj = filter_array(inv,(:get_object:));

	if( sizeof(obj) && dir =="enter" )
            return notify_fail("�и����ϵ�������: ��Ҫ�������أ����㱳�ϵ��˷������ȡ�\n");
	if ( dir == "enter" && me->query("family/family_name") !="������" ){
          if ( present("huangjin nao", me) || present("jingang zhao", me) || present("fumo nao", me)
            || present("huangjin nao", environment(me)) || present("jingang zhao", environment(me))
            || present("fumo nao", environment(me)))
		return notify_fail("ֻ����������˵��: �����ϻ��������˴����˿���Я�ر���������룬\nˡ���ĵ�ʧ���ˡ�\n");
          }
	return ::valid_leave(me, dir);
}
