// /d/hz/zilaidong.c ������

inherit ROOM;
void create()
{
        set("short","������");
        set("long", @LONG
��������ǰɽ�ֺ�ͤѭ�����ɽ����������¡�������ʹ������͵�
������������ǰ�ɸ���ɽ�µġ����������˵��������λʵ���ν������
�ļ��ÿ�괺�����ʵ�������ٹٵ��˼������Ա�ʾ��ũҵ�����ӡ�
LONG
        );
	set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"yuhuang",
		"southup" : __DIR__"shanlu2",
	]));
	setup();
}
