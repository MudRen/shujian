// cike.h �̿�

void init()
{	
	object ob = this_player();

	if (ob->query_temp("cike",1))
            	switch( random(3) ) {
		case 0:
			command("say ��������Ĵ̿�����������ܣ�");
                                    command("kill "+ob->query("id"));
			break;
		case 1:
			command("say Ϊ���ӱ��𣡴���ϰ���");
			command("kill "+ob->query("id"));
			break;
		case 2:
			command("say �Ҵ�ɱ�Ҽ����ӣ���ɱ���ۣ�");
			command("kill "+ob->query("id"));
			break;
	}

}
