// Room: /d/tianshan/kongchang.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "�ճ�");
	set("long", @LONG
ת��һ��ɽ�ţ���ǰͻȻ�ֳ�һƬĪ��Ŀճ����������ͣ�����ƽʵ����
�����ܣ����ǵ��ɼ�ѩɽ���ܵü���С����ǰ��һ����ɽ��ɽ�ƶ��ͣ���ɽ
���������������֣�ʹ�˲��ܿ���ȫò����һ������������С�����ƺ�������
ɽ�ĵ�·��
LONG);
	 set("exits", ([
                "east" :"/d/xingxiu/tianshan",
	        "west" :__DIR__"shanlu1",
        ]));       
	set("outdoors", "��ɽ");
	setup();
}
