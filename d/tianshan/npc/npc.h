// Npc: /d/tianshan/npc/npc.h
// By Linux
//modified by zhuifeng@SJFY

void attempt_apprentice(object ob)
{

		        
        if( (string)ob->query("gender") != "Ů��" ) {
                command ("say �Բ������չ�ֻ��Ů���ӡ�");
                return;
        }

        command("say �ף������СŮ����Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
        
         return;
}

