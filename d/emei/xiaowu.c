// xiaowu.c
// С��

inherit ROOM;
void create()
{
	set("short", "С��");
	set("long",@long
����һ��Сé�ݣ����ڰ���򵥣�һ��ľ����һ��ʯ����һֻľ��ܣ���
�ϰ��ż������顣ǽ�Ϲ���һ����üɽ��ɽˮ����ǽ�Ƿ���һ��С����������
���˶����ң�����ѷ���Щ��ͷ��ɨ��ȹ��ߡ�һ������Сʦ̫�����ڼ�ǰ
ר�Ķ��顣
long);
	set("exits",([
	"west" : __DIR__"caodi",
]));
	set("objects",([
		CLASS_D("emei") + "/wen-fei" : 1,
]));
	setup();
}