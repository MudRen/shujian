inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long",@long
��ɽ��������һ����Ȫ��ϵ�ϳ�������ɮ�������������䣬���һǧ��
�ٶ��ꡣ��˵Ȫ��ͨ��������������ӿȪ����ˮ������Ϊ�����µ���Ȫ����
ʯ�̡�����Ȫ�����֣�ϵ�������������⡣
long);
	set("outdoors", "����");
	set("objects",([
		__DIR__"obj/da-shitou" : 2,
	]));
	set("exits",([
		"eastdown" : __DIR__"wjszhuang",
	]));
	set("resource/water", 1);
	setup();
}
