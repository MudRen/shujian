// Skill: Emei-JianFa.c ¶ëÃ¼½£·¨
// Date:  AHA 97/06/24

inherit SKILL;

mapping *action = ({
(["action" : "$N×óÊÖ½£¾÷ÏòºóÐ±Ö¸£¬ÓÒÊÖ$wÍìÁË¸ö½£»¨£¬Ò»ÕÐ¡¸ÐéÊ½·Ö½ð¡¹£¬Ï÷Ïò"
             "$nµÄ$l",
  "force" : 200,
  "dodge" : 25,
  "skill_name" : "ÐéÊ½·Ö½ð",
  "lvl" : 0,
  "damage" : 60,
  "damage_type" : "´ÌÉË"
]),
(["action" : "$N×óÏ¥Î¢Çü£¬ÓÒ½ÅÉÏÇ°£¬½£ÉíÎ¢²ü£¬Ò»ÕÐ¡¸Ë³Ë®ÍÆÖÛ¡¹£¬Ï÷Ïò$nµÄ$l",
  "force" : 220,
  "dodge" : 30,
  "skill_name" : "Ë³Ë®ÍÆÖÛ",
  "lvl" : 9,
  "damage" : 70, 
  "damage_type" : "´ÌÉË"
]),
(["action" : "$N×óÊÖ½£Ö¸µãÔÚÓÒÊÖÍó¼ä£¬Æø¹á½£Éí£¬Ò»ÕÐ¡¸ÌúË÷ºá½­¡¹£¬ÍÆËÍ¶øÉÏ£¬"
             "$wÏ÷Ïò$nµÄ$l",
  "force" : 240,
  "dodge" : 35,
  "skill_name" : "ÌúË÷ºá½­",
  "lvl" : 19,
  "damage" : 80,
  "damage_type" : "´ÌÉË"
]),
(["action" : "$NÏòÇ°ÂõÉÏÒ»²½£¬Ò»ÕÐ¡¸ºÚÕÓÁéºü¡¹£¬$w»¯×÷ÊýÊ®±ú$w£¬Í»È»ÉÁµç°ã"
             "µØ´ÌÏò$nµÄ$l",
  "force" : 270,
  "dodge" : 25,
  "skill_name" : "ºÚÕÓÁéºü",
  "lvl" : 29,
  "damage" : 90, 
  "damage_type" : "´ÌÉË"
]),
(["action" : "$NÆøÄý½£¼â£¬Ò»ÕÐ¡¸ÔÂÂäÎ÷É½¡¹£¬$w×ÔÉÏ¶øÏÂ»®ÁË¸ö°ë»¡£¬½£¼âÉÁË¸£¬"
             "Ö±´Ì$nµÄ$l",
  "force" : 300,
  "dodge" : 30,
  "skill_name" : "ÔÂÂäÎ÷É½",
  "lvl" : 39,
  "damage" : 100, 
  "damage_type" : "´ÌÉË"
]),
(["action" : "$N²½·¨Ò»±ä£¬×ªµ½$nµÄÉíºó£¬ÊÖÖÐ$w×Ô×óÒ¸ÏÂ´©³ö£¬Ò»ÕÐ¡¸ÑÌÐ±Îíºá¡¹"
             "£¬´ÌÏò$nµÄ$l",
  "force" : 340,
  "dodge" : 40,
  "skill_name" : "ÑÌÐ±Îíºá",
  "lvl" : 49,
  "damage": 120,
  "damage_type" : "´ÌÉË"
]),
(["action" : "$NÓÒ½ÅµÅµØÌøÆð£¬ÊÖÖÐ$wÔÚ¿ÕÖÐÎè³ÉÒ»¶ä½£»¨£¬Ò»ÕÐ¡¸É³²Ý³¿ÄÁ¡¹£¬"
             "´ÌÏò$nµÄ$l",
  "force" : 380,
  "dodge" : 50,
  "skill_name" : "É³²Ý³¿ÄÁ",
  "lvl" : 59,
  "damage": 140,
  "damage_type" : "´ÌÉË"
]),
(["action" : "$NÊÖÖÐ$w×Ô×óÖÁÓÒ£¬ÓÖ×ÔÓÒÖÁ×óÁ¬»Î¾ÅÏÂ£¬Ò»ÕÐ¡¸ÇáÂÞÐ¡ÉÈ¡¹£¬´ÌÏò"
             "$nµÄ¾Å´¦´óÑ¨",
  "force" : 420,
  "dodge" : 60,
  "skill_name" : "ÇáÂÞÐ¡ÉÈ",
  "lvl" : 69,
  "damage": 160,
  "damage_type" : "´ÌÉË"
]),
(["action" : "$N½«ÄÚÁ¦×¢Èë½£Éí£¬ÊÖÖÐ$w»Ã³ÉÂúÌì½£Ó°£¬Ò»ÕÐ¡¸Ç§·å¾ºÐã¡¹£¬ÒÔÅÅ"
             "É½µ¹º£Ö®ÊÆ£¬´ÌÏò$nµÄ$l",
  "force" : 460,
  "dodge" : 50,
  "skill_name" : "Ç§·å¾ºÐã",
  "lvl" : 79,
  "damage" : 180,  
  "damage_type" : "´ÌÉË"
]),
(["action" : "$NË«ÊÖÎÕ½££¬Ö»Ìý¼û$wÔÚÄÚÁ¦¼¤µ´ÏÂ·¢³öÕóÕóÁúÒ÷Ö®Éù£¬Ò»ÕÐ¡¸½ð¶¥"
             "·ð¹â¡¹£¬´ÌÏò$nµÄ$l",
  "force" : 600,
  "dodge" : 45,
  "skill_name" : "½ð¶¥·ð¹â",
  "lvl" : 99,
  "damage" : 210, 
  "damage_type" : "´ÌÉË"
])
});

int valid_enable(string usage) 
  { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
  if ((int)me->query_skill("emei-jiuyang", 1) < 40)
     return notify_fail("ÄãµÄ¶ëÃ¼¾ÅÑô¹¦»ðºòÌ«Ç³£¬ÎÞ·¨Áì»á¸ßÉîµÄ¶ëÃ¼½£·¨¡£\n");
  if ((int)me->query("max_neili") < 300)
     return notify_fail("¶ëÃ¼ÎäÑ§ÒÔÄÚÁ¦Îª¸ù±¾£¬ÄãµÄÄÚÁ¦Ì«µÍÁË¡£\n");
  if ((int)me->query_skill("jinding-mianzhang", 1) < 50)
     return notify_fail("Ñ§Ï°¶ëÃ¼¹¦·ò£¬ÐèÒªÔúÊµµÄ»ù±¾¹¦¡£\n"
                        "ÄãµÄ½ð¶¥ÃàÕÆ»ðºòÌ«Ç³£¬ÎÞ·¨Áì»á¸ßÉîµÄ¶ëÃ¼½£·¨¡£\n");
  if ((int)me->query("shen") < 4000)
     return notify_fail("ÄãµÄÏÀÒåÕýÆøÌ«µÍ£¬²»ÄÜ´«ÊÚ¶ëÃ¼½£·¨¡£\n");
  if ((int)me->query("combat_exp") < 15000)
     return notify_fail("ÄãµÄÊµÕ½¾­ÑéÌ«²î£¬ÎÞ·¨Áì»á¸ßÉîµÄ¶ëÃ¼½£·¨¡£\n");
  return 1;
}

string query_skill_name(int level)
{
  int i = sizeof(action);

  while (i--)
    if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
  int i, level, max_neili;
  float factor;
  mapping act;

  level = (int) me->query_skill("emei-jianfa",1);

  for(i = sizeof(action); i > 0; i--)
     if(level > action[i-1]["lvl"]){
        act = action[NewRandom(i, 20, level/5)];
        max_neili = me->query("max_neili") - 400;
        if(max_neili > 100){ 
           factor = sqrt(sqrt(((float)max_neili)/100.0));
           act["force"] = (int)((float)act["force"]*factor);
           act["dodge"] = (int)((float)act["dodge"]*factor);
           act["damage"]= (int)((float)act["damage"]*factor);
        }
        return act;
     }
}

int practice_skill(object me)
{
  object weapon;

  if (!objectp(weapon = me->query_temp("weapon")) || 
       (string)weapon->query("skill_type") != "sword")
	  return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
  if(me->query_skill("emei-jiuyang")*2 < me->query_skill("emei-jianfa")*3)
    return notify_fail("ÄãµÄ¶ëÃ¼¾ÅÑô¹¦»ðºò²»×ã£¬ÎÞ·¨Áì»á¶ëÃ¼½£·¨¡£\n");
  if((int)me->query("qi") < 100)
    return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¶ëÃ¼½£·¨¡£\n");
  if((int)me->query("neili") < 100)
    return notify_fail("ÄãµÄÄÚÁ¦²»×ã£¬²»ÄÜÁ·¶ëÃ¼½£·¨¡£\n");
  if((int)me->query("jingli") < 50)
    return notify_fail("ÄãµÄ¾«Á¦Ì«²îÁË£¬²»ÄÜÁ·Ï°¶ëÃ¼½£·¨¡£\n");
  me->receive_damage("qi", 50);
  me->receive_damage("jingli", 30); 
  me->add("neili", -20);
  return 1;
}

string perform_action_file(string action)
{
  return __DIR__"emei-jianfa/" + action;
}
ÿ
