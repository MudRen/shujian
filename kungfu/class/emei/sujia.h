// emei sujia apprentice
// Lklv 2001.10.18 update

void attempt_apprentice(object ob)
{
	if ((string)ob->query("class") == "bonze" ){
		command ("say ��ֻ���׼ҵ��ӡ�");
		return;
	}
	if( (string)ob->query("gender") != "Ů��" ){
		command ("blush");
		command ("say ��ֻ���׼�Ů���ӡ�");
		return;
	}
	command ("say �ðɣ��Ҿ����������������׼ҵ��ӡ�");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class")!="bonze" ){
		ob->set("title", "�������׼ҵ���");
//		ob->set("class","emsujia");
	}
}
