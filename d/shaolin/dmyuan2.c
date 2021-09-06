// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19
// LinuX@SJ 04/03/01

#include <job_mul.h>
#include <ansi.h>

inherit ROOM;

void init()
{
	add_action("lingwu","lingwu");
}

void create()
{
	set("short", "��ĦԺ���");
	set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף����ٰ����ü
����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼�����ϱ�ɽǽ�Ǹ߼��ݶ���
����ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ��书���ţ������а��ż��Ű���ڭ��
�������ţ���λ��ɮ�����붨�С�
LONG
);

	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"dmyuan",
	]));

	setup();
}

string *valid_type = ({
"force",	"parry",	"dodge",	"unarmed",	"claw",
"cuff",		"finger",	"strike",	"hand",		"leg",
"sword",	"blade",	"dagger",	"brush",	"spear",
"hook",		"stick",	"staff",	"club",		"throwing",
"whip",		"axe",		"hammer",
});

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl,i;
	mapping skills = me->query_skills();
	int j;
	
	if (!me->query("luohan_winner")) {
		write("���ʮ���޺�����û���������ڴ�����\n");
		return 1;
	}
	if (!arg) {
		write("��Ҫ����ʲô��\n");
		return 1;
	}
	if (!me->query_skill(arg,1)) {
		write("�㲻�����ּ��ܡ�\n");
		return 1;
	}
	if (me->is_busy() || me->is_fighting()) {
		write("����æ���ء�\n");
		return 1;
	}
	if (arg == "force" && me->query_skill("force",1)<200) {
		write("�������ڵĻ����ڹ���Ϊ�����޷���������ڹ���\n");
		return 1;
	}
	if (me->query("potential") < 1) {
		write("���ʵս�еõ���Ǳ���Ѿ������ˡ�\n");
		return 1;
	}
	if (!(special=me->query_skill_mapped(arg))) {
		write("��ֻ�ܴ����⼼��������\n");
		return 1;
	}
	bl=me->query_skill(arg, 1);
	if (bl > me->query("jing") || me->query("jing") * 100 / me->query("max_jing") < 50) {
		me->receive_damage("jing",bl/2);
		write("��û�취���о���\n");
		return 1;
	}
	sl=me->query_skill(special,1);
	if (bl > sl) {
		write("���"+to_chinese(special)+"���費�����޷��������һ���"+to_chinese(arg)+"��\n");
		return 1;
	}
	write("���˼���룬��"+to_chinese(arg)+"�����������һ�㡣\n");
	
	if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") ){
			if (!random(5))
			write("������Լ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ���������Լ����������°빦����\n");
			if (!random(10))
			tell_room(environment(me), me->name() + "���ڲ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ��������ǽ�Ͻ�������\n", ({ me }));
		}
		
	i = me->query_int(1);

	foreach (string skill in keys(skills))
		if (member_array(skill, valid_type) != -1 && me->query_skill(skill, 1) > me->query("max_pot") - 105)
			j++;

	if ( j < 20 ) j = 20;

	me->receive_damage("jing", bl*2/5);
	me->add("potential", -random(2));
	if(me->query("potential")>0) me->add("potential", -random(2));
	i = i *3/2; //����pot���� ����β�� by Ciwei
	i = i *3/2;
	if (me->query("age") < 30)
		i += 30-me->query("age");
	if (me->query("age") > 60)
		i += me->query("age") - 60;
	j = to_int( i * j/5.0);
	
	/*�������ƿ�ʼ*/
        if (me->query("registered")==3)
        {
		j = j * SL_LINGWU_MUL * VIP_LINGWU_MUL /10000;
        }
        else
        {
		j = j * SL_LINGWU_MUL /100;
        }
        /*�������ƽ���*/ 
        //����ѧ�����
        if(me->worker_skill("highest")>350) j = j*7/10;
	else if(me->worker_skill("highest")>220) j = j*8/10;
	if(me->worker_skill("limit")>600) j = j*8/10;
	//���ƽ���                

   //�츳����ͯ������Ӱ��Ч����  by lsxk@hsbbs 2008/3/14
   if((int)me->query("relife/study/stzs",1) > 0){
       tell_object(me,HIG"��ֻ�����Լ��츳���ˣ���������Զ�ȱ��˸߳���࣡\n"NOR);
       j += j * (int)me->query("relife/study/stzs",1) * 1000 ;
   }

	if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") )
		me->improve_skill(arg, j*2);
	else
		me->improve_skill(arg, j);
		
	if (wizardp(me) && me->query("env/test"))
	write (sprintf("������Ϣ����������� %d �㣬�������� %d ��\n",j*2,j));
	return 1;
}
