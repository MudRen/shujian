// emei nigu apprentice
// Update by Lklv 2001.10.18
#include <ansi.h>
void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me = this_player();

	if ( me->query("family/family_name") != "������")
		return "����ɽ���ݲ���ʩ����ô�书��ǿ���ˡ�\n";
	if ((string)me->query("class")=="bonze" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶ�Ὺ�����Ц��\n";
	if ((string)me->query("gender") != "Ů��" )
		return "�����ӷ����գ����գ�ʩ������������ҷ𣬿�ȥ��ɽ�������ܽ䡣\n";
	if (me->query("marry"))
		return "�����ӷ����գ����գ���ҵ�ѽ�飬��������ˣ����ɷ���ô�찡��";
	me->set_temp("pending/join_bonze", 1);
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();
	string name, new_name;

	if (!me->query_temp("pending/join_bonze")) return 0;

	message_vision(
		"$N˫�ֺ�ʮ�����������ع���������\n\n"
		"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��һ����˿������ȥ��\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = "��" + name[<2..<1];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("smile");
	command("recruit " + me->query("id"));
	command("chat " + me->query("title") + me->query("name") +
		"�ڽ���" + NATURE_D->game_time() + "�ڶ�üɽ�ܽ���ң�ȡ����" + new_name + "��");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set("shen", 0);
	me->set("title", "�����ɵ��������");
	return 1;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������"){
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if ((string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������"){
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ����ܸ���ѧ�ա�");
		return;
	}
	if (ob_fam["generation"] == 0 ){
		command("say �����ӷ�ƶ������������ҵĵ����ˡ�");
		command("recruit " + ob->query("id"));
		return;
	}
	if (ob_fam["generation"] == (my_fam["generation"] + 1) ){
		command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
		command("recruit " + ob->query("id"));
	}
	if (ob_fam["generation"] <= my_fam["generation"]){
		command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");
		return;
	}
	return;
}
