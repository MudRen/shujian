/*
void init()
{
	::init();
	add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
}

int do_kill(string arg)
{
        object me, ob,ob2;
        me = this_player();
        ob2 = this_object();

        if (!arg) return 0;
        ob = present(arg, environment(me));
        if (ob == this_object() || ob == me) return 0;
        if (!ob || !ob->is_character()) return 0;

	if (ob->query("family/family_name") == "������") {
                if (me->query("family/family_name") == "������") {
                        message_vision(ob2->name()+"��$N�����ȵ��������˽�ɱ������ô���Լ���ͬ�Ŷ�ɱ����\n", me);
                }
                else {
                        message_vision(ob2->name()+"��$N�����ȵ����󵨿�ͽ����Ȼ�����������ף�\n", me);
                        kill_ob(me);
                }
                me->set("vendetta/������", 1);
                return 1;
        }
        return 0;
}
*/

//������<>���������� by fengyue

#include <ansi.h>

void attempt_apprentice(object ob)
{
       object me  = this_object();
       mapping ob_fam = ob->query("family");
       mapping my_fam = me->query("family");
       string name, new_name;

	if (!ob_fam || ob_fam["family_name"] != "������"){
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if (!ob->query("tls")){
		command("say "+RANK_D->query_respect(ob)+"���Ǳ��³��ҵ��ӣ��Ҳ�������! ");
		return;
	}
	if (ob_fam["generation"] <= my_fam["generation"] ){
		command("say "+RANK_D->query_respect(ob)+"��ƶɮ����ҵ���");
		return;
	}
	if (ob_fam["generation"] == (my_fam["generation"] + 1)){
		command("say "+ob_fam["master_name"]+"���������æ����͹���������ѧϰ�ɡ�");
		command("recruit " + ob->query("id"));
		return;
	}
	if((int)ob->query_skill("buddhism",1)<100){
		command("say ѧ��ֻ��Ϊ��ǿ���壬����ѧ��������������Ҫ���й��Ρ�");
		command("say ���ҿ�"+RANK_D->query_respect(ob)+"���ڷ������Ϊ�ƺ��������ɣ�");
		return;
	}
	if((int)ob->query_skill("qiantian-yiyang",1)<100){
		command("say ��������ѧ����������ޣ����ҿ�"+RANK_D->query_respect(ob)+"�ƺ���Ӧ���ڹ�������µ㹦��");
		return;
	}
	if((int)ob->query("shen") > 100 || (int)ob->query("shen")+100 <0 ){
		command("say ��������������֮�أ����ҿ�"+RANK_D->query_respect(ob)+"�ƺ��쳾δ��,���˼������С�");
		return;
	}
	if(ob->query("tls")&&(string)ob->query("class") == "bonze" ){
		command("nod");
		command("say �����ӷ����գ����գ�");
		message_vision("$N˫�ֺ�ʮ�����������ع���������\n",ob);
		name = ob->query("name");
		new_name = "��" + name[2..3];
		command("say ����ô�̿��ù���ƶɮ��������ɡ��ӽ��Ժ���ķ�������"+new_name+"��");
		ob->set("name", new_name);
		ob->set("shen", 0);
		command("recruit " + ob->query("id"));
		ob->set("title","������������ɮ" );
	}
}
