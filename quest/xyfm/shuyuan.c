// Room: /d/city/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG );
	set("item_desc", ([ /* sizeof() == 1 */
		"xuegui": "
		�ս����������տ���Ŀ��ҳ��
		ͨ��ʱ�������ζ�����ʫ����
		���������ʣ���ΰ�ʱ���ꡣ
		ҹ���Խ���������Ҫ������

	               ֪ʶ�޼ۡ�\n",
		"shujia":"һ��һ����Ⱦ����ܡ�\n",
		"board": "
       ����Ժ��ʥ�϶�ּ�Լ��������ѧλ��
\n" 
	]));
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"shuyuan2",
		"south" : __DIR__"dongdajie1",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (userp(me) && !wizardp(me)))
                return notify_fail("���������˽�����ң���\n");
        return 1;
}

//�Ǿ���
int is_mirror() { return 1; }