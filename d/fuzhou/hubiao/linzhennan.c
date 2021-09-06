// linzhennan.c ������
// modified by XiaoYao 98/12/16
// Modify by Lklv 2001.10.12

#include <ansi.h>

inherit NPC;
#include "hubiao.h";

int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

void create()
{
	set_name("������", ({ "lin zhennan", "lin", "zhennan" }));
	set("gender", "����");
	set("age", 45);
	set("long", "�����ǡ������ھ֡�������ͷ���������ϡ�\n");

	set("combat_exp", 30000);
	set("shen_type", 1);

	set("max_neili", 500);
	set("jiali", 10);
	set("no_get","�����϶�����˵̫���ˡ�\n");

	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("inquiry", ([
		"������լ" : "�����ҼҴ�ǰ��լԺ���Ѿ�û����ס�ˡ�",
		"�����ھ�" : (: ask_fuwei :),
		"Զͼ��" : (: ask_yuantu :),
		"��Զͼ" : "�ߣ�С������ôû��ò��ֱ���������䣡",
		"��а����" : (: ask_pixie:),
		"ͭǮ" : (: ask_tong:),
		"ͭ��" : (: ask_tong:),
		"Ѻ��" : (: test_dart :),
		"����" : (: test_dart :),
		"job" : (: test_dart :),
	]) );

	set("chat_chance", 2);
	set("chat_msg", ({
		CYN"������˵������������ھ����ⲻ����\n"NOR,
	}) );
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	carry_object(BINGQI_D("changjian"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

int ask_fuwei()
{
	say(CYN"��������ҫ��˵���������ּ��������ڣ�һ����������Զͼ�����괳�µ�������\n"
	"�������������ּҼҴ������ն����㺬��������н��յľ��棬��Ϊ������\n"
	"����һָ�Ĵ��ھ֡��������ᵽ�������ھ֡����֣�˭��Ҫ�����Ĵָ��˵һ\n"
	"�������ø����������磡����������������\n"NOR);
	this_player()->set_temp("marks/��1", 1);
	return 1;
}

int ask_yuantu()
{
	if (this_player()->query_temp("marks/��1")) {
		say(CYN"�����Ͽ�һ���̶���˵������Զͼ�����ҵ��游�������ھ�����һ�ִ���ġ�\n"
		"�����游����ʮ��·��а���������ھ֣������Ǵ��ڵ��޵��֡���ʱ�׵���\n"
		"Ӣ�ۼ���̫�����磬Ҳ��ȥ�����������յģ�����������������ʦ��������\n"
		"����֮ʱ��������а���������˼��С���\n"NOR);
		this_player()->set_temp("marks/��2", 1);
		return 1;
	}
	say(CYN"������˵������Զͼ�����ҵ��游����\n"NOR);
	return 1;
}

int ask_pixie()
{
	int p1, p2, p3, p4;

	if (this_player()->query("combat_exp") < 100000) {
		message_vision(CYN"$N��Ȼ��ŭ���ȵ�������Ҳ���������ּҵı�а���ף����Ҹ���ƴ�ˣ���\n" NOR, this_object());
		kill_ob(this_player());
	} 
	else {
		if (this_player()->query("quest/pixie/pxj_passwd"))
			say(CYN"�����ϲ��õ�˵�������Ҳ��Ƕ������������ҵĽ����������档��\n"NOR);
		else if (this_player()->query_temp("marks/��2")) {
			say(CYN"������һ����˵����������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ��ˣ����µĹ���\n"
			"���˲�֪��ϸ����ʵ���������档��\n"NOR);
			write(CYN"�����϶�һ�٣����ŵ���˵����������ȥ��ǰ�������Ҹ�����");
			p1=random(4)+1;
			p2=random(4)+1;
			p3=random(4)+1;
			p4=random(4)+1;
			this_player()->set("quest/pixie/pxj_passwd", p1*1000+p2*100+p3*10+p4);
			write(chinese_number(this_player()->query("quest/pixie/pxj_passwd")));
			write("\n��ͭǮ����һֱδ�����а��ء���\n"NOR);
		}
		else {
			message_vision(CYN"$N��Ȼ��ŭ���ȵ�������Ҳ���������ּҵı�а���ף����Ҹ���ƴ�ˣ���\n" NOR,this_object());
			kill_ob(this_player());
		}
		this_player()->delete_temp("marks/��1");
		this_player()->delete_temp("marks/��2");
	}
	return 1;
}

int ask_tong()
{
	int p;

	if (!(p=this_player()->query("quest/pixie/pxj_passwd")))
		say(CYN"������һ����Ц�����ӣ�˵������ô�쵽��һ���˵���ҪǮ����\n"NOR);
	else {
		write(CYN"�����ϵ���˵��������ȥ��ǰ�������Ҹ�����");
 		write(chinese_number(p));
 		write("��ͭǮ����һֱ\nδ�����а��ء���\n"NOR);
	}
	return 1;
}
