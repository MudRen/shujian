// app4.h
// ss 4 �� master

void attempt_apprentice(object ob)
{
	if(ob->query("shen") < 0 && ob->query("combat_exp") < 10000){
		command("say ����аħ���������������ɽ�ɣ������");
		return;
	}
	command("say �ðɣ�ʦ����Ҫ�Ҷ�����һЩ������������ɽ���ء�");
	command("recruit " + ob->query("id"));
}
