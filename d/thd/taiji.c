// Room: /u/jpei/thd/taiji.c

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "̫��");
	set("long", @LONG
������̫���㣬��һ�����������ϵ����ݾͱ������ˡ�������һ��������
�����ݣ�ͨ�����ǲ㡣̫���������ͳһ�壬������ת��Ϣ������ת������Ϊ
һ�����壬�������ν�Ļ���״̬����̫�����������˱仯����������������
̫�������ǡ�
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"liangyi",
	]) );

	set("no_clean_up", 0);
	setup();
}

void init()
{
	object me = this_player();

	me->delete_temp("wuxing");
	me->delete_temp("liangyi");
	me->delete_temp("sixiang");
	me->delete_temp("wuxing_total");
	me->delete_temp("wuxing_step");
	me->delete_temp("wuxing_error");
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

