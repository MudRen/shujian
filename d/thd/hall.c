// Room: /u/jpei/thd/hall.c

inherit ROOM;

string look_bagua();

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ǳ����ķ�����ǽ�Ϲ������������ֻ����������Ǻ��ں���
�ľ�Ʒ���������֮�϶��Ű�Ƭ��Ƭ�� ��������(bagua)ͼ����ȴ�ֲ���Ѱ��
�İ�����ô�ŵ����룬�������䣬��б���ƣ���Ȼ�����ܵĲ��ü���Э������
����һ��Сͤ�ӡ�
LONG
	);
	set("no_clean_up", 0);

	set("exits", ([
		"west" : __DIR__"zoulang1.c",
        "east" : __DIR__"shilu",
	]));

	set("item_desc", ([
		"bagua" : (: look_bagua :),
	]) );

/*	set("objects", ([
		__DIR__"npc/laoda.c":1,
	]));*/

	setup();
}

string look_bagua()
{
	int i, j, temp;
	int *bagua = ({0,1,2,3,4,5,6,7});
	string *bagua_name = ({"��","��","��","��","��","��","��","Ǭ"});
	string result;
	object me = this_player();

	for (i = 0; i < 8; i++)
	{
		j = random(8);
		while (j == i)
			j = random(8);
		temp = bagua[i];
		bagua[i] = bagua[j];
		bagua[j] = temp;
	}		
	for (i = 1; i < 9; i++)
		me->set_temp("bagua_" + i, bagua[i - 1]);
	result = "һ����ֵ������ԣ����水˳ʱ��˳�������ţ�";
	for (i = 0; i < 8; i++)
		result += bagua_name[bagua[i]];
	return result + "��\n";
}
