// shanpo.c
// ɽ�� 

inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long",@long
��ǰ��Ȼһ����ԭ���Ǿ��϶����һ��Сɽ�¡�ɽ�����Ӳݴ�������ܴ�
�ε���֦��ҡ��һ�ù����·��ż������ã����涼���������ָ������������
ɭɭ�ġ�
long);
	set("exits",([
		"enter" : __DIR__"jiulaodong1",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		CLASS_D("emei") + "/zhou-zhiruo" : 1,
		__DIR__"obj/kuloutou" : 1+random(2),
	]));
	setup();
}
