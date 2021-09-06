// by iceland

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include "cike.h";
int give_lun();
int give_lun2();

string* luns = ({
       BINGQI_D("gold-falun"),
       BINGQI_D("silver-falun"),
       BINGQI_D("bronze-falun"),
       BINGQI_D("iron-falun"),
       BINGQI_D("leaden-falun"),
});


void create()
{
        object weapon;
        set_name("���ַ���", ({ "jinlun fawang", "jinlunfawang","fawang" ,"jinlun"}));
        set("long",@LONG
����ĸ��ݣ��������ݣ�˫Ŀ������������̫��Ѩȴ�߸�͹���������ࡣ
���ܷ⡰�ɹŹ���һ��ʦ��������һ��ͨ�쳹�ص��񹦡�
LONG
        );
        set("title", HIY "�ɹŹ���һ��ʦ" NOR);
        set("gender", "����");
        set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 34);
        set("per", 22);

        set("max_qi", 9500);
        set("max_jing", 6500);
        set("eff_jingli", 7500);
        set("neili", 18000);
        set("max_neili", 18000);
        set("jiali", 100);
        set("combat_exp", 4500000);
        set("score", 28000);
        set("unique", 1);

        set_skill("huanxi-chan", 200);
        set_skill("literate", 200);
        set_skill("force", 360);
        set_skill("longxiang-boruo", 360);
        set_skill("dodge", 380);
        set_skill("yuxue-dunxing", 380);
        set_skill("hammer", 380);
        set_skill("xiangfu-lun", 380);
        set_skill("hand", 340);
        set_skill("dashou-yin",340);
        set_skill("claw", 340);
        set_skill("tianwang-zhua", 340);
        set_skill("parry", 360 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hammer", "xiangfu-lun");
        map_skill("parry", "xiangfu-lun");
        map_skill("hand","dashou-yin");
        map_skill("claw","tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("������", 10, "����");
        set("inquiry", ([
                "����" : (: give_lun  :),
                "����" : (: give_lun  :),
                "�����" : (: give_lun2  :),
                
       ]));
        set("lun_count",5);
        set("lun_count2",1);
        set("class", "huanxi");
        set("chat_chance", 2);     
        set("chat_msg", ({
		CYN"���ַ�����Ȼ������ʮ����������������ڻ��ͨ���������������ǵڶ��ˣ�\n"NOR,
		CYN"���ַ����߷ߵĵ�����ԭ���˲�����أ������˶࣬��������һӵ���ϡ�\n"NOR,
		CYN"���ַ����߷ߵĵ�: �ߣ�����ƾ��һ��֮������ȡ����������֮λ��\n"NOR,
	}) );
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "shield jinlun fawang" :),
                (: perform_action, "hammer.wushuai" :), 
	}));

        set_temp("apply/damage", 70);
        set_temp("apply/dodge", 80);
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 60);

        setup();
	if (clonep()){
                weapon = unew(BINGQI_D("gold-falun"));
                if (!weapon) weapon = unew(BINGQI_D("silver-falun"));
                if (!weapon) weapon = unew(BINGQI_D("bronze-falun"));
                if (!weapon) weapon = unew(BINGQI_D("iron-falun"));
                if (!weapon) weapon = unew(BINGQI_D("leaden-falun"));
                weapon->move(this_object());
                weapon->wield();
                carry_object("/d/xueshan/npc/obj/longxiang-jiasha")->wear();       
                add_money("gold",2);
        }
}

void reset()
{
	set("lun_count2", 1);
}

void attempt_apprentice(object ob)
{
       if ((string)ob->query("family/family_name") != "������") {
                command("say"+ RANK_D->query_respect(ob) +
                        "���Ǳ��ɵ��ӣ������ﵷʲô�ң���");
                return;
        }

        if ((int)ob->query_skill("longxiang-boruo", 1) < 150) {
                command("say �Ҵ����¸����书�����ڹ��ศ��ɡ�");
                command("say"+ RANK_D->query_respect(ob) +
                        "�ٰ�����ͨ��������������б��ŵ��ڹ��ɡ�");
                return;
        }
        if( (string)ob->query("gender") == "����" ){
                command ("say ʩ�������ȱ����˵�����ն�����������...");
                return;
        }

if( ob->query("family/master_name") == "Ѫ������" || ob->query("family/master_name") == "�Ħ��" )
 {
command("say "+ RANK_D->query_respect(ob) + "������ʦָ�㣬�Ҳ������㣡");
return ;
}
        if( (int)ob->query_con(1) < 30) {
               command("sigh");
               command("say"+ RANK_D->query_respect(ob) +"�����̫������˸����");
               command("shake");
               return;
        }

        if (!(int)ob->query_temp("win_deb")){
                command ("say �㻹�������ҵ��Ӵ�������������Ϊ�ɡ�\n");
                return;
	} 
        command("say ��Ҳ������Ѱһ�������ϼѵĵ��������²����㲻�˼����������Ϊʦ��");
        if (!ob->query("fawang")){
		command("chat* ����˵�����ã�"+ ob->query("name") + RANK_D->query_respect(ob) + "����˫ȫ���ɴ����²���\n");
		command("chat* ���쳤Ц�����������������꣬�����ҵ����ˣ�����֮�����޺��ӣ���");
	}
	command("recruit " + ob->query("id"));
	ob->set("fawang", 1);
	ob->set("title", HIY "�����½��ַ������µ���" NOR);
}

int give_lun()
{ 
	mapping fam; 
	object me, ob,lun;

	me = this_object();
	ob = this_player();
       
	if (ob->query_temp("give_lun") == 1){
		command("say �㲻�Ǹմ������������������㵱�Ұ׳հ���");
		return 1;
	}
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������"){
		command("say ���뱾��������������֪�˻��Ӻ�̸��");
		return 1;
	}
	if ( objectp(present("iron falun", (ob))))  { 
		command("say �����ϲ����Ѿ���������");
		return 1;  
	} 
	if ( objectp(present("iron falun", environment(me)))){ 
		command("say ���ϲ�����ֻ���������۾�Ϲ������");
		return 1;
	} 
      
	if(query("lun_count") < 1){
		command("say �������ˣ�����������û���ֹ���ʹ�á�");
		return 1;
	}
	add("lun_count",-1);       
	lun = unew( luns[random(sizeof(luns))] );
	if(clonep(lun)){
		lun->move(ob);
		command("say �ðɣ���ֻ�������û�ȥ�ú����С�");
		ob->set_temp("give_lun",1);
		message_vision("$N����$nһֻ���֡�\n", me, ob);
		return 1;
	}
	command("say �������ˣ���ʱ�����û�ж���ķ��ֿ��Ը����ˡ�");
	return 1;
}

int give_lun2()
{ 
	mapping fam; 
	object me, ob,lun2;

	me = this_object();
	ob = this_player();
       
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������"){
		command("say ���뱾��������������֪�˻��Ӻ�̸��");
		return 1;
	}
	if ((int)ob->query_skill("longxiang-boruo", 1) < 200) {
		command("say �Ҵ����¸����书�����ڹ��ศ���, ���������Ϊ�������Ҳ����İѱ��ɱ��ｻ���㡣");
		return 1;
	}
      
	if(query("lun_count2") < 1){
		command("say �������ˣ�����������û�з���ֹ���ʹ�á�");
		return 1;
	}
	add("lun_count2",-1);       
	lun2 = unew(BINGQI_D("bestfalun"));
	if( clonep(lun2)){
		lun2->move(ob);
		command("say �ðɣ����Ǳ���֮������֣����û�ȥ�ú�������������š�");
		message_vision("$N����$nһֻ����֡�\n", me, ob);
		return 1;
	}
	command("say �������ˣ�������Ѹ����ʦ��ȡ���ˡ�");
	return 1;
}
