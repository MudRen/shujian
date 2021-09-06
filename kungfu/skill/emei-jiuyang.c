// Skill: Emei-JiuYang.c ¶ëÃ¼¾ÅÑô¹¦
// Date : AHA 97/06/22

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
  int level = (int)me->query_skill("emei-jiuyang", 1);
  int changquan = (int)me->query_skill("emei-changquan", 1);
  
  int t = 1, j;
  for (j = 1; j < level / 10; j++) t *= 2;

  if ( me->query("gender") == "ÎÞÐÔ" )
     return notify_fail("¶ëÃ¼¾ÅÑô¹¦Á·µÄÊÇºÆÈ»ÕýÆø£¬ÒÔ¹«¹«ÎÞ¸ùÎÞÐÔÖ®Éí£¬
                         ÈçºÎÐÞµÃ£¡\n");

  if ((int)me->query_skill("force", 1) < 10)
     return notify_fail("ÄãµÄ»ù±¾ÄÚ¹¦»ðºò»¹²»¹»¡£\n");

  if ( changquan < 20 ) 
     return notify_fail("ÄãµÄ¶ëÃ¼³¤È­ÐÞÎªÌ«µÍ£¬ÎÞ·¨ÁìÎò¶ëÃ¼¾ÅÑô¹¦¡£\n");  

  if (level > 10 && (int)me->query("shen") < t * 100) 
     return notify_fail("ÄãµÄÏÀÒåÕýÆøÌ«µÍÁË¡£\n");

  return 1;
}

int practice_skill(object me)
{
  return notify_fail("¶ëÃ¼¾ÅÑô¹¦Ö»ÄÜÓÃÑ§(learn)µÄÀ´Ôö¼ÓÊìÁ·¶È¡£\n");
}

string exert_function_file(string func)
{
  return __DIR__"emei-jiuyang/" + func;
}

ÿ