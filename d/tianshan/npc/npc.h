// Npc: /d/tianshan/npc/npc.h
// By Linux
//modified by zhuifeng@SJFY

void attempt_apprentice(object ob)
{

		        
        if( (string)ob->query("gender") != "女性" ) {
                command ("say 对不起，灵鹫宫只收女孩子。");
                return;
        }

        command("say 咦，不错的小女孩嘛，我就收下你了。");
        command("recruit " + ob->query("id"));
        
         return;
}

