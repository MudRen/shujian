// /d/city/kedian.c

inherit ROOM;
#define WEI_FILE "/d/city/npc/weixiaobao"

void create()
{
	set("short", "������ջ");
	set("long", @LONG
������������¡�ı�����ջ������������οͶ�ѡ���ڴ���š�һ������
�ĵ�С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ���ջ�����ǽ�Ϲ���
һ����Ŀ������(zhaopai)�������ǽ�Ϲ���һ�����Ϲ��ڵĸ�ʾ(gaoshi)��
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("no_fight",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
		"zhaopai" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		"/clone/npc/xu" :1,
		"/clone/npc/zha" :1,
//                 __DIR__"npc/jiunan" : 1,
		NPC_D("jianke1") : 1,
	]));

	set("exits", ([
		"east" : __DIR__"kedian/pianting",
		"west" : __DIR__"beidajie2",
		"up" : __DIR__"kedian2",
	]));
	set("incity",1);
	setup();
	"/clone/board/kedian_b"->foo();
}

void init()
{
        object *obs = filter_array(children(WEI_FILE), (: clonep :));
        object ob;
        
        if (sizeof(obs) < 1)  
        {
                ob = new(WEI_FILE);
                if (!objectp(ob)) return;
                ob->start_weapon();
                ob->move_other("");
        }
        return;
}


int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid") != "������ջ" && dir == "up" )
		return notify_fail("��ô�ţ����ס���Ǳ�����ջ����\n");
	if ((string)me->query_temp("rent_paid") == "������ջ" && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���Ϊ���Ǳ�����ջ�ź����أ�\n");

	return ::valid_leave(me, dir);
}
