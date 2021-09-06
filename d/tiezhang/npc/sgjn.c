// sgjn.c  �Ϲٽ���

#include <ansi.h>
inherit NPC;

int ask_wumu();
int ask_dongxi();
int ask_xinyuan();
int ask_jueji();
int ask_baowu();

void create()
{
	set_name("�Ϲٽ���", ({ "shangguan jiannan", "shangguan", "jiannan"}));
        set("long",
        "�������ĺ��룬ɢ�ҵ�ͷ��������ǰ�������������أ�\n"
        "����ϥ���µ�˫�Ⱥ�Ȼ��ȥ�����ù��౻һ�������������̶���һ���ʯ���ϡ�\n");
        set("gender", "����");
        set("age", 75);
        set("attitude", "peaceful");
        set("unique", 1);
        set("shen_type", 20);
        set("str", 35);
        set("int", 30);
        set("con", 1);
        set("dex", 1);

        set("max_qi", 4000);
        set("max_jing", 4000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
	set("eff_jingli",5000);
	set("max_jingli",5000);
	set("jingli",5000);
        set("combat_exp", 1800000);
        set("score", 400000);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
		(: perform_action, "strike.tianlei" :)
        }));

        set_skill("force", 200);
        set_skill("guiyuan-tunafa", 200);
        set_skill("dodge", 200);
        set_skill("shuishangpiao", 200);
        set_skill("strike", 200);
        set_skill("tiezhang-zhangfa", 200);
        set_skill("parry", 200);
        set_skill("literate", 180);
        set_skill("blade", 200);
        set_skill("liuye-daofa", 200);
        set_skill("tiezhang-xinfa",200);

        map_skill("force", "guiyuan-tunafa");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "tiezhang-zhangfa");
        prepare_skill("strike", "tiezhang-zhangfa");
        map_skill("blade", "liuye-daofa");

        create_family("���ư�", 13, "����");

        set("inquiry", ([
		"name" : "�Ϸ����Ϲ٣������ϡ��������ư�ĵ�ʮ����������\n",
		"here" : "��ǧ��Ϊ�˽��������������ص�������ɽ�����������ʯ�ң��ߣ�\n",
		"��������Ķ���" : (: ask_dongxi :),
		"��������" : (: ask_wumu :),
		"��Ը" : (: ask_xinyuan :),
		"����" : (: ask_jueji :),
		"����" : (: ask_baowu :),
        ]));

        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
		"�Ϲٽ���ŭ���������Ϸ�����ؼ����գ���Ҫ������������Ķ�����ʬ��Σ�����\n",
		"�Ϲٽ���̾����������֪�������������ںδ��������˵���ѽ��������\n",
	}) );
}

void attempt_apprentice(object ob)
{

 string name, new_name;
name = ob->query("name");
new_name = "�Ϲ�" + name[<4..<1];
	if ((int)ob->query("shen") <=10000) {
		command("shake");
		command("say ��Ŀ¶�׹⣬�������֮��������������֮�ˣ��㻹�ǻ�ȥ�ɣ�");
		return;
        }
	if ((int)ob->query_skill("guiyuan-tunafa", 1) < 140) {
                command("shake");
                command("say ���ư���书�����Թ�Ԫ���ŷ�Ϊ�����ģ�");
                command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
                command("sigh");
                return;
        }
	if ((int)ob->query_skill("tiezhang-zhangfa", 1) < 140) {
                command("shake");
                command("say �����Ʒ����Ұ���������");
                command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
                return;
        }
	if ((int)ob->query_temp("mark/����")) {
                command("say �ðɣ��Ҿ��������ˡ�ϣ���㲻Ҫ����ʧ����");
ob->set("name", new_name);
 command("say �ӽ��Ժ���ͽ���" + new_name + "��ϣ�����ܰ����ƹ�������");
                command("recruit " + ob->query("id"));
                command("say ����������ҵ����£��͵��̿���ϰ���ƾ������Ұ�\n"
                        "��ɽ�����������������ԭ�����ľ��������Ʒ��������䲻������\n"
                        "ʮ���ƣ������Ʒ�����������ڽ���ʮ����֮�ϡ�");
                command("haha");
                command("look " + ob->query("id"));
                command("hmm");
                command("say ��������Ʒ��������㲻������δ�����衣���Ƶ�\n"
                        "�������ڣ�����Ҫ���Ԫ���ŷ����ϣ���ս���У�����ʹ��һ�о�\n"
                        "���������������������������ף��޼᲻�ݡ�");
                command("pat " + ob->query("id"));
                command("say ����Ϊʦ�ͽ��˾����������㣡");
                }
                else
                {
                command("say �Ϸ�һֱ�ܵ���������飬���ܷ�ȥ�����������ң�\n");
                return;
	}
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
            ob->set("title", HIM"���ư��Ϲٰ�������"NOR);
	ob->set("class","brigand");
}
int ask_dongxi()
{
command("say ������ǧ�����������ĵ��ӣ�������������һ���������Ҳ���ޱ���\n"
"���������ڣ��������Ұ�����ܴ����²���������������ʢ��������δ��ã���Ҫѧ����\n"
"�ľ���������������δ�̣�����δ�Ӵ��ڡ�����˻������ģ���Ϊ�Ϸ��˽������Ϸ��\n"
"��֮�ʣ�����˫�ȴ�ϣ��������������ùǣ��������ʯ��֮�У����Ϸ򽫾�������������\n");
	this_player()->set_temp("marks/asksgjn",1);
	command("sigh");
	return 1;
}

int ask_jueji()
{
	command("say �����������--����������ս����perform tianlei�������ͷų��޼᲻��\n"
	"����������߷������ˣ�ʮ�ְԵ���\n");
	return 1;
}

int ask_wumu()
{
	object ob = this_player();

	if (!present("zitie", ob) || ob->query_temp("marks/asksgjn")!=1) {
		command("say �ٺ٣�����������������ǹ�ϵ�����������Ĵ��£�������ܷ��ĸ����㣿\n");
		return 1;
	}
	command("look " + ob->query("id"));
	command("say ��λ" + RANK_D->query_respect(ob) + "��Ȼ���������졷�������������ұ������ˣ��ðɣ��Ϸ��\n"
	"������������¸�����ɣ�\n");
	command("say �������������������������µ�һ�����������м������о����̵�Ҫ����\n"
	"�Ϸ������Ǻ����ҽ����Ĳ��£�������������һ��֮�£����Ϊ�ܣ������������ư\n"
	"���������˵�ⲿ������ڻʹ�֮�У��;�����и��֣�����͵�˻��������뽫֮����һ\n"
	"�����İ����Ľ��졣���������Һ�Ȼ����ޱ䣬�����ԸҲδ�ܴ�ɡ�\n");
	this_player()->set_temp("marks/����1", 1);
	return 1;
}

int ask_xinyuan()
{
	if ((int)this_player()->query_temp("marks/����1")) {
		command("say �Ϸ���������һ��ɽˮ�������а����ŷ�����ĵص㣬�ҽ��⸱��������\n"
		"ţ�Ҵ�,��������ҵ��⸱�����Ϳ��԰�������ָ��ȥ�����������ˡ�\n");
		this_player()->set_temp("find_shanshui", 1);
		return 1;
	}
	command("say �Ϸ�ȴ�и�δ�˵���Ը�������ܸ����㣡\n");
	return 1;

}

int accept_object(object who, object ob)
{
        if ((string)ob->query("name")=="���������项") {

                command(
"say ������������Ҫ�ҵ��������飬�Ȿ�������ؼ����գ������ϲ����۰���\n"
"������һ��Ȿ�飬�Ҳ��������ģ�\n");

                this_player()->set_temp("mark/����", 1);
                }
       else return notify_fail("�Ϲٽ���˵����" + RANK_D->query_respect(who) +
"���Ϸ���Щ��������֪�Ǻ����⣿\n");

        return 1;
}

int ask_baowu()
{
        object me  = this_player();
        mapping fam = me->query("family");

        if(!fam || fam["family_name"] != "���ư�"){
                command("say "+RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 0;
                }

         if(fam["master_name"] != "�Ϲٽ���" ){
                command("say ����ʲô���������ҹ���ȥ! ");
                write(HIY"һ�ɾ޴��������ӭ�������������Ƴ���ʯ��"NOR);
                me->move("/d/tiezhang/wmfeng");
                return 1;
                }
         else{
         command("say ���������ֻ�����㣬����������");
         write("�����ڵڶ�ָ�ڵĶ�Ѩ�\n");
         me->set_temp("marks/baowu", 1);
         return 1;
         }
}
