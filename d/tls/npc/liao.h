#include <ansi.h>
string ask_for_join()
{
	object me = this_player();

	if( me->query_temp("tls_chujia"))
		return "�����ӷ�ʩ�������Ѿ��ʹ����𣿻�����ʦ��bai)��\n";
	if( (string)me->query("gender") == "Ů��" )
		return "�����ӷ𣡳�ʥ��������Ժ��Ůʩ������������ҷ𣬿�ȥ����ɽ�ܽ䡣\n";
	if( me->query("tls") && (string)me->query("class")=="bonze" )
		return "�����ӷ𣡴�ʦ�����������ڳ���֮�ˣ��ιʸ�ƶɮ�������Ц��\n";
	if( me->query("marry"))
		return "�����ӷ�ʩ���Ѿ���飬����ң���������е����ӿ���ô�찡��";
	if(me->query_temp("tls_app")) {
		me->delete_temp("tls_app");
		me->set_temp("tls_chujia", 1);
		return "�����ӷ����գ����գ�ʩ�����ǽ������٣��Կ����������³��ң���Ͱ�ʦ(bai)�ɡ�\n";
	}
	return "�����ӷ����գ����գ�����ɮ��������ʩ��������ذɡ�\n";
}

void attempt_apprentice(object me)
{
	object ob;
	mapping ob_fam, fam;
	string name, new_name;
	ob = this_object();

	ob_fam = ob->query("family");
	fam = me->query("family");

	if(me->query("gender") != "����" ){
		command ("say �����ӷ�"+RANK_D->query_respect(me)+"��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}
	if(!fam || fam["family_name"] != "������"){
		command("say "+RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if (me->query("tls") && fam["generation"] <= ob_fam["generation"] ){
		command("say "+RANK_D->query_respect(me)+"��ƶɮ����ҵ���");
		return;
	}
	if (me->query("tls") && fam["generation"] == (ob_fam["generation"] + 1)){
		command("say "+fam["master_name"]+"������η�æ����͹���������ѧϰ�ɡ�");
		command("recruit " + me->query("id"));
		return;
	}
	if(me->query_temp("tls_chujia")){
		command("nod");
		command("say �����ӷ����գ����գ�");
		message_vision("$N˫�ֺ�ʮ�����������ع���������\n\n"
			"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",me, ob);
		name = me->query("name");
		new_name = "��" + name[<2..<1];

		command("chat " + name + "�ڽ���" + NATURE_D->game_time() + "����������ȳ��ң�ȡ����" + new_name + "��\n");
		command("say �ӽ��Ժ���ķ�������" + new_name + "��");
		me->set("name", new_name);
		me->set("class", "bonze");
		me->set("shen", 0);
		me->delete_temp("tls_chujia");
		me->set("tls",1);
		command("recruit " + me->query("id"));
		ob->set("title", "������������ʦ" );
		return;
	}
	else {
		if(!me->query("tls")) {
			command ("say �����ӷ𣡱���ɮ��������ʩ��������ذɡ�");
			return;
		}
	}
}
