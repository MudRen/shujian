// app3.h
// ss 3 �� master

void attempt_apprentice(object ob)
{
	if (ob->query_skill("hanbing-zhenqi",1) < 100){
		command("say ��ĺ���������������죬�ٻ�ȥ�����ɡ�");
                return;
        }
	if (ob->query_skill("force",1) < 100){
		command("say ��Ļ����ڹ���������죬�ٻ�ȥ�����ɡ�");
                return;
        }
        command("say �ðɣ����������������ѧ���գ��ǵ�Ҫ�ڷ�������������ɡ�");
        command("recruit " + ob->query("id"));
}