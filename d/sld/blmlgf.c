// blmlgf.c
// ������������
inherit ROOM;
void create()
{
	set("short","������");
	set("long",@long
�˴��ǰ����Ž���ƽʱ����ϰ��ĵط������п�ǽ�и������ܣ�����
���Ų��ٱ������Ա߷��ż���ʯ���������м���һ��÷��׮�����ӵĴ���
������ż���ɳ����
long);
	set("exits",([
		"east" : __DIR__"blm",
	]));
	set("objects",([
		BINGQI_D("dagger") : 2,
	]));
	setup();
}
