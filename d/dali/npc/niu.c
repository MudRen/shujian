// niu.c

#include <ansi.h>

inherit NPC;

void create()
{
     set_name("��ɫ��Ů",({"niu","nu"}));
    set("gender","Ů��");
set("per",30);
set("age",19);
 set("long", "������ò������ķ�����һ����΢Ц������һ����\n");
                       set("combat_exp", 350000);
set("attitude", "friendly");
  set("rank_info/respect", "����");
	set("inquiry",([
      "name" : "�Ҿ���ɱ����ү����������ģ��������ṩ�����",
"here" : "����ɱ����ү�Ļ���ң��Ǳ��а��ᣬ����ȥ�ɣ�",
"yuj" : "����ֻ֪���� MUD������ʲô�������� ",
"snowman" : " ��ϲ����ѩ�򣬾������ҵ�һЩ����Ҳ����ѩ���档",
"jpei" : "�ܾ�û���ˣ���˵û���������ʺš�",
"bbb" : "����һ��Գ�ɱ��,ģ��������ȥ,�Ϳ�ϧ...��,��Щ���������.",
"rumors" : "�������ʦ�Ƕ�ϲ���ң��ҿ�æ�������ˣ�����ɱ���ٽм����ҵĽ�������",
"ahunter" : "�������������У�Ҳ�������ң�������˵Ҫɱ������",
"swlb" : "���ǳ���åһ�����Ҳ��ź��������� AK-47 ǹ����в�ҡ�",
  "keepon" : "һ�������Ĵ����ˣ��������﹤������̰��СǮ�����ң���ϲ���Ҳ���ϲ���úܡ�",
"qingyun" : "�������̺����࣬�ҳ�������Ħ,���ˣ���������С�ѡ�",
"look" : "�������...�ҿ����������棬ȥ������Ħ������Ϲ����",
"dubei" : "�������...��Ȼ�����Ҳ��ÿ����������϶��Ҷ��ֶ��š�",
"cool" : "COOL ʲô COOL��cool �ȽϿ�����",
"lius" : "�����ڿ����ڣ������������������",
"acep" : "�������ˣ�û����Сë��һ�����Ͷ����ҿ���ʲôҲ������",
"fay" : "�ɰ���С���������Ŀɱ��Ҳ�Զ�ˡ�",
	]) );
set_skill("sword",250);
set_skill("dodge",250);
set_skill("parry",250);
          setup();
	carry_object(__DIR__"obj/b-cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch(random(3)) {
		case 0:
                        say( "��Ů����Ц������λ" + RANK_D->query_respect
(ob)
              + "��ɱ����ү���Ҹ�������Ȱ�Ħ����\n");
            break;
		case 1:
 say("��Ů��" + RANK_D->query_respect(ob) + "üĿ���飬˵������ү���˰�?СŮ�ӻ��Ǵ����һ�����ѵ��㲻�������? \n");
            break;
		case 2:
                        say( "��ŮЦ�����˵������λ" + RANK_D->query_respect
(ob)
                                + "����Ҫ������˼�������ɣ�\n");
            break;
        case 3:
			break;
	}
}
